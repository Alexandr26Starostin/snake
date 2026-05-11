#ifndef SNAKE_H_
#define SNAKE_H_

#include <iostream>
#include <cstddef>
#include <list>

#include "const.h"

enum class direction_t
{
    UP    = 0,
    LEFT  = 1,
    RIGHT = 2,
    DOWN  = 3
};

class point_t
{
public:
    point_t (size_t x_init = 0, size_t y_init = 0) : x(x_init), y(y_init) {}

    void set_coordinates (size_t x_new = 0, size_t y_new = 0) 
    {
        x = x_new;
        y = y_new; 
    }

    void print_inf () const 
    {
        std::cout << "------------------------------------------------------" << std::endl;
        std::cout << "x = " << x << std::endl;
        std::cout << "y = " << y << std::endl;
        std::cout << "------------------------------------------------------\n" << std::endl;   
    }

private:
    size_t x, y;
};

class snake_t
{
public:
    snake_t () : direction(direction_t::UP)
    {
        size_t x_init = SNAKE_CONST::MAX_VALUE_X / 2;
        size_t y_init = SNAKE_CONST::MAX_VALUE_Y / 2;

        point_t init_coordinates (x_init, y_init);

        for (size_t index = 0; index < SNAKE_CONST::INIT_LENGTH_SNAKE; index++)
        {
            snake.push_back(init_coordinates);
            init_coordinates.set_coordinates (x_init, ++y_init);
        }
    }

    void print_inf () const 
    {
        size_t index_point = 0;  //0                => head of snake
                                 //snake.size() - 1 => tail of snake

        std::cout << "\n-------------------------------------------------------------------------------------------\n" 
                  << GREEN_LIGHT_SHAKE <<"snake content:\n" << WHITE_USUAL_TEXT << std::endl;
        std::cout << "length = " << snake.size() <<  std::endl;
        std::cout << "------------------------------------------------------\n" << std::endl;

        for (const auto& point : snake)
        {
            std::cout << PURPLE_INDEX << "index_point" << WHITE_USUAL_TEXT << " = " << index_point++ << std::endl;
            point.print_inf ();
        }

        std::cout << "-------------------------------------------------------------------------------------------\n" << std::endl;
    }

    void increase_snake (size_t x_new, size_t y_new) 
    {
        point_t new_point (x_new, y_new);
        snake.push_front(new_point);
    }

    void change_direction (direction_t new_direction)
    {
        direction = new_direction;
    }

    ~snake_t ()
    {
        snake.clear();
    }


private:
    std::list<point_t> snake;
    direction_t        direction;
};

#endif