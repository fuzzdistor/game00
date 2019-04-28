//SceneNode.hpp
#ifndef SCENENODE_HPP
#define SCENENODE_HPP

#include "Category.hpp"

#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>

#include <vector>
#include <set>
#include <memory>
#include <utility>

struct Command;
class CommandQueue;

class SceneNode 
    : public sf::Transformable, public sf::Drawable , private sf::NonCopyable
{
public:
    typedef std::unique_ptr<SceneNode> Ptr;
    typedef std::pair<SceneNode*, SceneNode*> Pair;


public:
    explicit    SceneNode(Category::Type category = Category::None);


public:
    void        attachChild(Ptr child);
    Ptr         detachChild(const SceneNode& node);

    void        update(sf::Time dt, CommandQueue& commands);

    void        onCommand(const Command& command, sf::Time dt);

    sf::Vector2f    getWorldPosition() const;
    sf::Transform   getWorldTransform() const;

    virtual unsigned int    getCategory() const;

    void        checkSceneCollision(SceneNode& sceneGraph, std::set<Pair>& collisionPairs);
    void        checkNodeCollision(SceneNode& node, std::set<Pair>& collisionPairs);
    void        removeWrecks();
    virtual sf::FloatRect   getBoundingRect()

private:
    std::vector<Ptr>    mChildren;
    SceneNode*          mParent;
    Category::Type      mDefaultCategory;
};

#endif