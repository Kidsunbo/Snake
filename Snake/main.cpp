#include <iostream>
#include "snake.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


using namespace std;

int main()
{

    sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getDesktopMode().width/2,sf::VideoMode::getDesktopMode().height/2),"Pong",sf::Style::Close|sf::Style::Resize);
    window.setVerticalSyncEnabled(true);
    Snake snake(window);
    while(window.isOpen()){


        sf::Event event;

        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }

        }

        window.clear(sf::Color::Black);
        window.draw(snake);
        window.display();



    }

    return 0;
}
