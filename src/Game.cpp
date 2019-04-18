//Game.cpp
#include "Game.hpp"

#include <SFML/Graphics.hpp>

const sf::Time          TimePerFrame = sf::seconds(1/60.f);
const sf::VideoMode     WindowSize(400, 300);


Game::Game() 
{
};

void Game::run()
{
    sf::RenderWindow window(WindowSize, "game00");

    int frame = 0;
	
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
        
    sf::Font font;
    font.loadFromFile("../resources/fonts/pixelarial.TTF");
    
    sf::Text text;
    text.setFont(font);

    sf::Event event;
    
    sf::Clock clock;

    while(window.isOpen())
    {
        while(window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
                window.close();

        text.setString(std::to_string(frame));

        sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > TimePerFrame)
	    {
            timeSinceLastUpdate -= TimePerFrame;
            window.clear(sf::Color::Green);
            window.draw(text);
            window.display();
            frame++;
        }

    }
};


