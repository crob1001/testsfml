#include <SFML/Graphics.hpp>
#include <ctime> //for random
#include <string>
#include <cmath>
#include <vector>
#include <iostream>

#include "headers/ball.hpp"
#include "headers/paddle.hpp"

int main()
{

    sf::Clock deltaClock;

    __int8 state = 0;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    
    sf::RenderWindow window(sf::VideoMode(1000, 600), "Test", sf::Style::Close, settings);

    sf::Texture backgroundimg;
    backgroundimg.setSmooth(true);
    backgroundimg.loadFromFile("resources/background.png");
    sf::RectangleShape background(sf::Vector2f(1000, 600));
    background.setTexture(&backgroundimg);
    background.setFillColor(sf::Color(255, 255, 255, 100));

    Ball ball = Ball(15.0f,
    sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));

    Paddle paddle1 = Paddle(sf::Vector2f(25.0f, 100.0f),
    sf::Vector2f(98, window.getSize().y / 2),
    sf::Color(255, 50, 50, 255));

    Paddle paddle2 = Paddle(sf::Vector2f(25.0f, 100.0f),
    sf::Vector2f(window.getSize().x - 98, window.getSize().y / 2),
    sf::Color(50, 50, 255, 255));

    sf::Text score;
    sf::Font font;
    font.loadFromFile("resources/Orbitron.ttf");
    score.setFont(font);
    score.setString(std::to_string(paddle1.score) + " SCORE " + std::to_string(paddle2.score));
    score.setFillColor(sf::Color(0, 0, 0, 255));
    score.setCharacterSize(24);
    sf::FloatRect textRect = score.getLocalBounds();
    score.setOrigin(textRect.left + textRect.width/2.0f,
               textRect.top  + textRect.height/2.0f);
    score.setPosition(window.getSize().x / 2, 20);

    sf::Time dt = deltaClock.restart();

    while (window.isOpen()) {

        sf::Event event;
        
        while (window.pollEvent(event))
        {
                    switch (event.type){
                        case sf::Event::KeyPressed:
                        std::cout << event.key.code << std::endl;

                        case sf::Event::Resized:
                            window.setSize(sf::Vector2u(1000,600));
                            break;
                        
                        // case sf::Event::LostFocus:
                        //     state = 1;
                        //     break;

                        case sf::Event::Closed:
                            window.close();
                            break;
            }
        }

        ball.oldpos[0] = ball.getPosition().x;
        ball.oldpos[1] = ball.getPosition().y;

        ball.move(ball.direction[0] * ball.velocity[0],
        ball.direction[1] * ball.velocity[1]);

        if (ball.getPosition().x + ball.getRadius() > window.getSize().x){
            ball.move(0, window.getSize().x - (ball.getPosition().x + ball.getRadius()));
            paddle2.score += 1;
        }
        if (ball.getPosition().x - ball.getRadius() < 0){
            ball.move(0, 0 - (ball.getPosition().x - ball.getRadius()));
            paddle1.score += 1;
        }

        if (ball.getPosition().y + ball.getRadius() > window.getSize().y){
            ball.move(0, window.getSize().y - (ball.getPosition().y + ball.getRadius()));
            ball.direction[1] = ball.direction[1] * -1;
        }
        if (ball.getPosition().y - ball.getRadius() < 0){
            ball.move(0, 0 - (ball.getPosition().y - ball.getRadius()));
            ball.direction[1] = ball.direction[1] * -1;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || 
        sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                paddle2.move(0,-5);
            else
                paddle2.move(0,5);
        else
            paddle2.move(0,0);
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || 
        sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                paddle1.move(0,-5);
            else
                paddle1.move(0,5);
        else
            paddle1.move(0,0);

        if (paddle2.getPosition().y + (paddle2.getSize().y / 2) > window.getSize().y){
            paddle2.move(0, window.getSize().y - (paddle2.getPosition().y + (paddle2.getSize().y / 2)));
        } 
        if (paddle2.getPosition().y - (paddle2.getSize().y / 2) < 0){
            paddle2.move(0, 0 - (paddle2.getPosition().y - (paddle2.getSize().y / 2)));
        }

        if (paddle1.getPosition().y + (paddle1.getSize().y / 2) > window.getSize().y){
            paddle1.move(0, window.getSize().y - (paddle1.getPosition().y + (paddle1.getSize().y / 2)));
        }
        if (paddle1.getPosition().y - (paddle1.getSize().y / 2) < 0){
            paddle1.move(0, 0 - (paddle1.getPosition().y - (paddle1.getSize().y / 2)));
        }

        window.clear();
        window.draw(background);
        window.draw(ball);
        window.draw(score);
        window.draw(paddle1);
        window.draw(paddle2);
        window.display();

        sf::sleep(sf::seconds(.01 - dt.asMilliseconds()));
        dt = deltaClock.restart();
    }

    return 0;
}