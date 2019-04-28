#ifndef RESOURCEHOLDER_HPP
#define RESOURCEHOLDER_HPP

#include <map>
#include <string>
#include <memory>
#include <stdexcept>
#include <cassert>


template <typename Resource, typename Identifier>
class ResourceHolder
{
public:
	//Typical resource load function. Valid for Textures, Fonts...
	void		load(Identifier id, const std::string& filename);
	//Overload for two parameter load calls like on sf::Shader
	template <typename Parameter>
	void		load(Identifier id, const std::string& filename, const Parameter& secondParam);

	Resource&			get(Identifier id);
	const Resource&		get(Identifier id) const;

private:
	void	insertResource(Identifier id, std::unique_ptr<Resource> resource);


private:
	std::map<Identifier, std::unique_ptr<Resource>>	mResourceMap;
};

#include "ResourceHolder.inl"
#endif