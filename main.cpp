#include <SFML/Graphics.hpp>
#include <vector>
#include "headers/ball.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(300, 300), "Test");

    // Ball test = Ball();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        //window.draw();
        window.display();
    }

    return 0;
}