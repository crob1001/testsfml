#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "headers/ball.hpp"

int main()
{

    sf::Clock deltaClock;

    __int8 state = 0;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    
    sf::RenderWindow window(sf::VideoMode(800, 800), "Test", sf::Style::Close, settings);

    //window.setFramerateLimit(60);
    // window.setVerticalSyncEnabled(true);

    // Ball test = Ball();

    struct Ball {
    int pos[2] = {0, 0};
    float vel[2] = {10, 20};
};

    Ball ball;

    sf::CircleShape shape(50.f);
    shape.setFillColor(sf::Color(255, 0, 0));

    sf::Time dt = sf::Time::Zero;

    while (window.isOpen()) {

        sf::Event event;
        
        while (window.pollEvent(event))
        {
            // switch (state){
            //     case 0: //default state

                    // shape.setPosition(ball.pos[0], ball.pos[1]);
                    // ball.pos[0] = ball.pos[0] + float(ball.vel[0] * dt.asSeconds()/1000);
                    // ball.pos[1] = ball.pos[1] + float(ball.vel[1] * dt.asSeconds()/1000);


                    switch (event.type){
                        case sf::Event::KeyPressed:
                            std::cout << event.key.code << std::endl;
                            // if (event.key.code == 36){
                            //     state = 1;
                            //     std::cout << state << std::endl;
                            // }
                            break;

                        case sf::Event::MouseMoved:
                            std::cout << "new mouse x: " << event.mouseMove.x << std::endl;
                            std::cout << "new mouse y: " << event.mouseMove.y << std::endl;
                            shape.setPosition(event.mouseMove.x - 50, event.mouseMove.y - 50);
                            break;

                        case sf::Event::Resized:
                            window.setSize(sf::Vector2u(800,800));
                            break;
                        
                        case sf::Event::LostFocus:
                            state = 1;
                            break;

                        case sf::Event::Closed:
                            window.close();
                            break;       
                    // }
                // break;

                // case 1: //menu
                //     switch (event.type){ 
                //         case sf::Event::KeyPressed:
                //             std::cout << event.key.code << std::endl;
                //             if (event.key.code == 36){
                //                 state = 0;
                //                 std::cout << state << std::endl;
                //             }
                //             break;

                //         case sf::Event::Resized:
                //             // std::cout << "new width: " << event.size.width << std::endl;
                //             // std::cout << "new height: " << event.size.height << std::endl;
                //             break;
                        
                //         case sf::Event::LostFocus:
                //             break;

                //         case sf::Event::Closed:
                //             window.close();
                //             break;       
                //     }
                // break;
            }
        }

        window.clear();
        window.draw(shape);
        window.display();

        dt = deltaClock.restart();
    }

    return 0;
}