//Game.cpp
#include "Game.hpp"
#include "Entity.hpp"

#include <SFML/Graphics.hpp>

const sf::Time          TimePerFrame = sf::seconds(1/60.f);
const sf::VideoMode     WindowSize(400, 300);


Game::Game() 
{
};

void Game::run()
{
    sf::RenderWindow window(WindowSize, "game00");
    window.setFramerateLimit(60);
	

    sf::Texture texture;
    texture.loadFromFile("../resources/images/default.png");

    sf::Sprite sprite;
    sprite.setTexture(texture);

    

    sf::Font font;
    font.loadFromFile("../resources/fonts/pixelarial.TTF");
    
    sf::Event event;
    

    while(window.isOpen())
    {
        while(window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
                window.close();

        window.clear(sf::Color::Green);
        window.draw(sprite);
        window.display();
        }

    }
};


