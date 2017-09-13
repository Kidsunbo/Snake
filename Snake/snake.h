#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <deque>
#include <memory>

class Snake:public sf::Drawable{

private:

    std::deque<std::shared_ptr<sf::RectangleShape>> deq;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const{
        for(auto i : deq){
            target.draw(*i);
    }
    }

public:
    Snake(sf::Window& window){
        std::shared_ptr<sf::RectangleShape> temp = std::make_shared<sf::RectangleShape>();
        temp->setSize(sf::Vector2f(10,10));
        temp->setFillColor(sf::Color::Yellow);
        temp->setPosition(window.getSize().x/2-5,window.getSize().y/2-5);

    }
};


#endif // SNAKE_H
