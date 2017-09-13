#include <iostream>
#include "snake.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;

int main()
{
    sf::RenderWindow window;
    window.setSize(sf::Vector2u(500,500));
    window.setVerticalSyncEnabled(true);
    Snake snake(window);
    while(window.isOpen()){


        sf::Event event;

        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }

        }

        window.clear(sf::Color::White);
        window.draw(snake);
        window.display();



    }

    return 0;
}
