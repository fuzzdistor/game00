//World.hpp
#ifndef	WORLD_HPP
#define	WORLD_HPP

#include <Game/ResourceHolder.hpp>
#include <Game/ResourceIdentifiers.hpp>
#include <Game/SceneNode.hpp>
#include <Game/SpriteNode.hpp>
#include <Game/Character.hpp>
#include <Game/CommandQueue.hpp>
#include <Game/Command.hpp>
#include <Game/SoundPlayer.hpp>

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTexture.hpp>

#include <array>
#include <queue>


namespace sf
{
	class RenderTarget;
}

class World : private sf::NonCopyable
{
public:
	enum Layer
	{
		Background,
		ObjectsBackLayer,
		CharacterLayer,
		ObjectsFrontLayer,
		FrontLayer,
		LayerCount,
	};

	struct SpawnPoint
	{
		SpawnPoint(Character::Type type, float x, float y)
		: type(type)
		, x(x)
		, y(y)
		{
		}

		bool isInsideView(sf::FloatRect viewBounds, sf::Vector2u textureBounds)
		{
			sf::FloatRect spawnRect(x, y, textureBounds.x, textureBounds.y);
			return spawnRect.intersects(viewBounds);
		}
	


		Character::Type type;
		float x;
		float y;
	};


public:
	typedef	std::array<SceneNode*, LayerCount> SceneLayers;


public:
	World(sf::RenderTarget& outputTarget, FontHolder& fonts, SoundPlayer& sounds);


public:
	void 		update(sf::Time dt);
	void 		draw();

	CommandQueue& 		getCommandQueue();

private:
	void 		loadTextures();
	void 		adaptPlayerPosition();
	void 		adaptPlayerVelocity();
	void 		handleCollisions();
	void 		updateSounds();

	void 		buildScene();
	void 		addCharacters();
	void 		addCharacter(Character::Type type, float x, float y);
	void 		spawnCharacters();
	void 		destroyEntitiesOutsideView();
	
	sf::FloatRect	getViewBounds() const;
	sf::FloatRect	getSceneBounds() const;



private:
	sf::RenderTarget& 		mTarget;
	sf::RenderTexture		mSceneTexture;
	sf::View 				mWorldView;
	TextureHolder			mTextures;
	FontHolder& 			mFonts;
	SoundPlayer& 			mSounds;

	SceneNode 			mSceneGraph;
	SceneLayers			mSceneLayers;
	CommandQueue 		mCommandQueue;

	sf::FloatRect		mWorldBounds;
	sf::Vector2f 		mSpawnPosition;
	sf::Vector2f		mScrollSpeed;
	Character*			mPlayerCharacter;

	std::vector<SpawnPoint> 	mCharacterSpawnPoints;
	std::vector<Character*> 	mActiveCharacters;
};

#endif
