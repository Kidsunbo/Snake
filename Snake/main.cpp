#include <iostream>
#include "snake.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <functional>
#include <thread>


using namespace std;

int main()
{

    sf::RenderWindow window(sf::VideoMode(900,600),"Snake",sf::Style::Close|sf::Style::Resize);
    window.setVerticalSyncEnabled(true);
    Snake snake(window);

    std::thread t(std::bind(&Snake::update_with_thread,&snake));
    t.detach();
    while(window.isOpen()){


        sf::Event event;

        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::P)){
                snake.set_x_y(0,0);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                snake.set_x_y(0,-1);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                snake.set_x_y(0,1);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                snake.set_x_y(1,0);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                snake.set_x_y(-1,0);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
                snake.add_speed();
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
                snake.sub_speed();
            }

        }

        window.clear(sf::Color::Black);
        window.draw(snake);
        window.display();



    }

    return 0;
}
