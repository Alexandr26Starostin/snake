#ifndef SNAKE_H_
#define SNAKE_H_

#include <iostream>
#include <cstddef>
#include <list>

#include "const.h"

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

    size_t x_read () const {return x;}
    size_t y_read () const {return y;}

private:
    size_t x, y;
};

class big_snake_t;

class snake_t
{
public:
    snake_t (symbol_code_t snake_code_init = symbol_code_t::SNAKE_1) : direction(direction_t::UP), snake_code(snake_code_init)
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

    // void add_snake_in_printing_list ()
    // {
    //     for (const auto& point : snake)
    //     {
            
    //     }
    // }

private:
    std::list<point_t> snake;
    direction_t        direction;
    symbol_code_t      snake_code;

    friend class big_snake_t;     //TODO iterator
};

//--------------------------------------------------------------------------------------------------------------------
//big_snake

class big_snake_point_t : public point_t
{
public:

    big_snake_point_t (size_t x_init = 0, size_t y_init = 0, symbol_code_t snake_code_init = symbol_code_t::SNAKE_1) : point_t {x_init, y_init}, 
                                                                                                                    snake_code {snake_code_init} {}

    void set_big_snake_point (size_t x_new = 0, size_t y_new = 0, symbol_code_t snake_code_init = symbol_code_t::SNAKE_1) 
    {
        set_coordinates (x_new, y_new);
        
        snake_code = snake_code_init;
    }

    symbol_code_t snake_code_read () const {return snake_code;}

private:
    symbol_code_t snake_code;
};

//-------------------------------------------------------------------------------
class view_t;

class big_snake_t 
{
public:
    ~big_snake_t ()
    {
        list_coord_of_snakes.clear();
    }

    void add_snake_in_list (const snake_t& ptr_snake)
    {
        symbol_code_t snake_code = ptr_snake.snake_code;

        for (const auto& point : ptr_snake.snake)      //TODO iterator
        {
            add_big_snake_point_in_list (point, snake_code);
        }
    }

private:
    std::list<big_snake_point_t> list_coord_of_snakes;

    void add_big_snake_point_in_list (point_t point, symbol_code_t snake_code)
    {
        big_snake_point_t init_coordinate (point.x_read (), point.y_read (), snake_code);
        list_coord_of_snakes.push_back (init_coordinate);
    }

    friend class view_t;   //TODO iterator
};

#endif