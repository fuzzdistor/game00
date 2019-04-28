//ResourceHolder.inl

template <typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string& filename)
{
    //Create and load the resource into a unique pointer
    std::unique_ptr<Resource> resource(new Resource());
    if (!resource->loadFromFile(filename))
        throw std::runtime_error("ResourceHolder::load failed to load the file: " + filename);
    
    //If the resource is succesfully loaded, move the pointer to mResourceMap
    instertResource(id, std::move(resource));
}

template <typename Resource, typename Identifier>
template <typename Parameter>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string& filename, const Parameter& secondParam)
{
    //Create and load the resource to a unique pointer
    std::unique_ptr<Resource> resource(new Resource);
    if (!resource->loadFromFile(filename, secondParam))
        throw std::runtime_error("ResourceHolder::load failed to load the file: " + filename);
   
    //If the resource is succesfully loaded, move the pointer to mResourceMap
    instertResource(id, std::move(resource));
}

template <typename Resource, typename Identifier>
Resource& ResourceHolder<Resource, Identifier>::get(Identifier id)
{
    //Search for resource by id on mResourceMap
    auto found = mResourceMap.find(id);
    assert(found != mResourceMap.end());

    //return the unique_ptr to the resource
    return *found->second;
}

template <typename Resource, typename Identifier>
const Resource& ResourceHolder<Resource, Identifier>::get(Identifier id) const
{
    //Search for resource by id on mResourceMap
	auto found = mResourceMap.find(id);
	assert(found != mResourceMap.end());

    //return the unique_ptr to the resource
	return *found->second;
}

template <typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::insertResource(Identifier id, std::unique_ptr<Resource> resource) 
{
	//insert an Identifier-Resource pair into mResourceMap and check for success
	auto inserted = mResourceMap.insert(std::make_pair(id, std::move(resource)));
	assert(inserted.second);
}