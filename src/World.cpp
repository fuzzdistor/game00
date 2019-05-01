//World.cpp
#include <Game/World.hpp>
#include <Game/TextNode.hpp>
#include <Game/SoundNode.hpp>
#include <Game/World.hpp>

#include <SFML/Graphics/RenderTarget.hpp>

#include <algorithm>
#include <vector>
#include <cmath>
#include <limits>


World::World(sf::RenderTarget& outputTarget, FontHolder& fonts, SoundPlayer& sounds)
: mTarget(outputTarget)
, mSceneTexture()
, mWorldView(outputTarget.getView())
, mTextures()
, mFonts(fonts)
, mSounds(sounds)
, mSceneGraph()
, mSceneLayers()
, mWorldBounds(0.f, 0.f, mWorldView.getSize().x, mWorldView.getSize().y)
, mSpawnPosition(mWorldView.getSize().x / 2.f, mWorldView.getSize().y * 0.75)
, mScrollSpeed({0.f, 0.f})
, mPlayerCharacter(nullptr)
, mCharacterSpawnPoints()
, mActiveCharacters()
{
	mSceneTexture.create(mTarget.getSize().x, mTarget.getSize().y);

	loadTextures();
	buildScene();

	mWorldView.setCenter(mSpawnPosition);
}

void World::update(sf::Time dt)
{
	mWorldView.move(mScrollSpeed * dt.asSeconds());
	mPlayerCharacter->setVelocity(0.f, 0.f);

	destroyEntitiesOutsideView();
	
	while(!mCommandQueue.isEmpty())
		mSceneGraph.onCommand(mCommandQueue.pop(), dt);
	adaptPlayerVelocity();

	handleCollisions();
	
	mSceneGraph.removeWrecks();

}

void World::loadTextures()
{
	mTextures.load(Textures::Background,"resources/images/Background.png");
	mTextures.load(Textures::Buttons, 	"resources/images/Buttons.png");
	mTextures.load(Textures::Default,	"resources/images/Default.png");
	mTextures.load(Textures::Entities,	"resources/images/Entities.png");
}

void World::buildScene()
{
	for (std::size_t i = 0; i < LayerCount; i++)
	{
		Category::Type category = (i == CharacterLayer) ? Category::PlayerCharacter : Category::None;

		SceneNode::Ptr layer(new SceneNode(category));
		mSceneLayers[i] = layer.get();

		mSceneGraph.attachChild(std::move(layer));
	}

	sf::Texture& backgroundTexture = mTextures.get(Textures::Background);
	backgroundTexture.setRepeated(true);

	std::unique_ptr<SceneNode> backgroundSpriteNode(new SpriteNode(backgroundTexture));
	backgroundSpriteNode->setPosition(mWorldBounds.left, mWorldBounds.top);
	mSceneLayers[Background]->attachChild(std::move(backgroundSpriteNode));

	std::unique_ptr<SoundNode> soundNode(new SoundNode(mSounds));
	mSceneGraph.attachChild(std::move(soundNode));

	std::unique_ptr<Character> player(new Character(Character::Ghost, mTextures, mFonts));
	mPlayerCharacter = player.get();
	mPlayerCharacter->setPosition(mSpawnPosition);
	mSceneLayers[CharacterLayer]->attachChild(std::move(player));

	addCharacters();
}

void World::addCharacters()
{
	addCharacter(Character::Exorcist, 80.f, 80.f);
}

void World::addCharacter(Character::Type type, float x, float y)
{
	SpawnPoint spawnPoint(type, x, y);
	mCharacterSpawnPoints.push_back(spawnPoint);
}

void World::spawnCharacters()
{
	for (auto spawn : mCharacterSpawnPoints)
		if (spawn.isInsideView(getViewBounds(), mTextures.get(spawn.type)->getSize()))
		{
			std::unique_ptr<Character> character(new Character(spawn.type, mTextures, mFonts));
			character->setPosition(spawn.x, spawn.y);

			mSceneLayers[CharacterLayer]->attachChild(std::move(character));

			mCharacterSpawnPoints.erase(spawn);
		}
}

void World::destroyEntitiesOutsideView()
{
	Command command;
	command.category = Category::NPCharacter;
	command.action = derivedAction<Entity>([this] (Entity& e, sf::Time)
	{
		if (!getViewBounds().intersects(e.getBoundingRect()))
		{
			e.remove();
		}
	});

	mCommandQueue.push(command);
}
