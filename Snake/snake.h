#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <deque>
#include <memory>
#include <random>

class Snake:public sf::Drawable{

private:

    int grid_x = 0;
    int grid_y = 0;
    int food_x = 0,food_y = 0;
    sf::RectangleShape food;

    std::deque<std::shared_ptr<sf::RectangleShape>> deq;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const{
        for(auto i : deq){
            target.draw(*i);
    }
        //food
        target.draw(food);
    }

public:
    Snake(sf::Window& window){
        std::shared_ptr<sf::RectangleShape> temp = std::make_shared<sf::RectangleShape>();
        temp->setSize(sf::Vector2f(29,29));
        temp->setFillColor(sf::Color::Yellow);
        temp->setPosition(window.getSize().x/2-5,window.getSize().y/2-5);
        deq.push_back(temp);

        //grid
        grid_x=window.getSize().x/30;
        grid_y=window.getSize().y/30;

        //food
        std::random_device rd;
        std::uniform_int_distribution<int> distribution_x(0,grid_x);
        std::uniform_int_distribution<int> distribution_y(0,grid_y);
        food_x = distribution_x(rd);
        food_y = distribution_y(rd);
    }
};


#endif // SNAKE_H
