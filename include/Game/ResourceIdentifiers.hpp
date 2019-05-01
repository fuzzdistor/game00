//ResourceIdentifiers.hpp
#ifndef RESOURCEIDENTIFIERS_HPP
#define RESOURCEIDENTIFIERS_HPP

// Forward declaration of some SFML classes
namespace sf
{
	class Texture;
	class Font;
	class Shader;
	class SoundBuffer;
}

namespace Textures
{
	enum ID
	{
		Entities,
		Background,
		Buttons,
		Default,
	};
}

namespace Shaders
{
    enum ID
    {
		BrightnessPass,
		DownSamplePass,
		GaussianBlurPass,
		AddPass,       
    };
}

namespace Fonts
{
	enum ID
	{
		Main,
	};
}

namespace SoundEffect
{
	enum ID
	{
		Button,
	};
}

namespace Music
{
	enum ID
	{
		MenuTheme,
		ChillTune,
	};
}

// ResourceHolder forward declaration 
template <typename Resource, typename Identifier>
class ResourceHolder;

//Type definitions for common resource containers
typedef ResourceHolder<sf::Texture, Textures::ID>			TextureHolder;
typedef ResourceHolder<sf::Font, Fonts::ID>					FontHolder;
typedef ResourceHolder<sf::Shader, Shaders::ID>				ShaderHolder;
typedef ResourceHolder<sf::SoundBuffer, SoundEffect::ID>	SoundBufferHolder;

#endif
