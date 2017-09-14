#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <deque>
#include <memory>
#include <random>
#include <iostream>
#include <thread>


class Snake:public sf::Drawable{

private:

    int grid_x = 0;
    int grid_y = 0;
    int food_x = 0,food_y = 0;
    sf::RectangleShape food;
    int tail = 5;
    int x=0,y=0;


    int speed = 0;

    std::deque<std::shared_ptr<sf::RectangleShape>> deq;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const{
			for (auto& i : deq) {
				target.draw(*i);
			}

			//food
			target.draw(food);

	}

public:
    Snake(sf::Window& window){

        for(int i = 0;i!=tail;i++){
			auto temp = std::make_shared<sf::RectangleShape>();
			temp->setSize(sf::Vector2f(29,29));
			temp->setFillColor(sf::Color::Yellow);
			temp->setPosition(5*30,5*30);
			deq.push_front(temp);
        }

        //grid
        grid_x=window.getSize().x/30-1;
        grid_y=window.getSize().y/30-1;

        //food
        std::random_device rd;
        std::uniform_int_distribution<int> distribution_x(0,grid_x);
        std::uniform_int_distribution<int> distribution_y(0,grid_y);
        food_x = distribution_x(rd);
        food_y = distribution_y(rd);
        food.setFillColor(sf::Color::Red);
        food.setSize(sf::Vector2f(29,29));
        food.setPosition(food_x*30,food_y*30);


    }

	void update_with_thread() {

			if (x != 0 || y != 0) {

				//std::lock_guard<std::mutex> lm(m);
				auto temp = std::make_shared<sf::RectangleShape>();
				auto x_s = (int)(this->deq.front()->getPosition().x + x * 30);
				auto y_s = (int)(this->deq.front()->getPosition().y + y * 30);
				if (x_s < 0) x_s += (grid_x * 30 + 30);
				if (y_s < 0) y_s += (grid_y * 30 + 30);
				temp->setPosition(x_s % (grid_x * 30 + 30), y_s % (grid_y * 30 + 30));
				temp->setSize(sf::Vector2f(29, 29));
				temp->setFillColor(sf::Color::Yellow);
				deq.push_front(temp);
				if (this->meet_the_food()) {
					std::random_device rd;
					std::uniform_int_distribution<int> distribution_x(0, grid_x);
					std::uniform_int_distribution<int> distribution_y(0, grid_y);
					food_x = distribution_x(rd);
					food_y = distribution_y(rd);
					food.setFillColor(sf::Color::Red);
					food.setSize(sf::Vector2f(29, 29));
					food.setPosition(food_x * 30, food_y * 30);
					tail++;
				}
				else {
					deq.pop_back();
				}
				std::this_thread::sleep_for(std::chrono::milliseconds(100));
			}
	}

    bool meet_the_food(){
        return this->deq.front()->getPosition()==this->food.getPosition()? true:false;
    }

    void set_x_y(int x, int y){

        this->x = x;
        this->y = y;
    }

    void add_speed(){

        if(speed <900)
        this->speed+=100;
    }
    void sub_speed(){

        if(speed >0)
        this->speed-=100;
    }

};


#endif // SNAKE_H
