#ifndef VIEW_H_
#define VIEW_H_

#include <termios.h>
#include <unistd.h>

#include "const.h"
#include "snake.h"

inline void set_canonical_mode () 
{
    struct termios tty;

    //get current parameters of terminal
    if (tcgetattr(STDIN_FILENO, &tty) != 0) 
    {
        std::cerr << __FILE__ << ":" << __LINE__ << "\nError: tcgetattr" << std::endl;
        return;
    }

    //turn on canonical mode: ICANON and ECHO
    tty.c_lflag |= (ICANON | ECHO);
    
    //apply settings
    tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}

class view_t
{
public:
    void reset_symbols_codes ()
    {
        size_t y_index = 0;
        size_t x_index = 0;
        
        for (; x_index < SNAKE_CONST::MAX_VALUE_X; x_index++)
            symbols_codes[y_index][x_index] = symbol_code_t::BOARD_HOR;

        x_index = 0;

        for (++y_index; y_index < SNAKE_CONST::MAX_VALUE_Y - 1; y_index++)
        {
            symbols_codes[y_index][x_index++] = symbol_code_t::BOARD_VER;

            for (; x_index < SNAKE_CONST::MAX_VALUE_X - 1; x_index++)
            {
                symbols_codes[y_index][x_index] = symbol_code_t::CLEAR;
            }

            symbols_codes[y_index][x_index] = symbol_code_t::BOARD_VER;
            x_index = 0;
        }

        for (; x_index < SNAKE_CONST::MAX_VALUE_X; x_index++)
            symbols_codes[y_index][x_index] = symbol_code_t::BOARD_HOR;

    } 

    void move_big_snake_in_symbols_code (const big_snake_t& ptr_big_snake)
    {
        size_t x_index = 0, 
               y_index = 0;

        symbol_code_t snake_code = symbol_code_t::CLEAR;

        for (const auto& point_snake : ptr_big_snake.list_coord_of_snakes)   //TODO iterator
        {
            x_index    = point_snake.x_read ();
            y_index    = point_snake.y_read ();
            snake_code = point_snake.snake_code_read ();

            if (symbols_codes[y_index][x_index] != symbol_code_t::CLEAR)
            {
                code_position (__FILE__, __LINE__); 
                std::cerr << RED_ERROR << "Error: have collision" << WHITE_USUAL_TEXT << std::endl;   //TODO exceptions
            }

            symbols_codes[y_index][x_index] = snake_code;
        }
    }

    void print_symbols_codes ()
    {
        //std::cout << std::endl;

        symbol_code_t symbol_code = symbol_code_t::CLEAR;

        for (size_t y_index = 0; y_index < SNAKE_CONST::MAX_VALUE_Y; y_index++)
        {
            for (size_t x_index = 0; x_index < SNAKE_CONST::MAX_VALUE_X; x_index++)
            {
                symbol_code = symbols_codes[y_index][x_index];

                switch (symbol_code)
                {
                    case symbol_code_t::CLEAR:
                    {
                        std::cout << " ";
                        break;
                    }


                    case symbol_code_t::BOARD_HOR:
                    {
                        std::cout << "-";
                        break;
                    }

                    case symbol_code_t::BOARD_VER:
                    {
                        std::cout << "|";
                        break;
                    }

                    case symbol_code_t::APPLE:
                    {
                        std::cout << " ";
                        break;
                    }

                    case symbol_code_t::SNAKE_1:
                    {
                        std::cout << " ";
                        break;
                    }

                    case symbol_code_t::SNAKE_2:
                    {
                        std::cout << " ";
                        break;
                    }

                    case symbol_code_t::SNAKE_3:
                    {
                        std::cout << " ";
                        break;
                    }

                    case symbol_code_t::SNAKE_4:
                    {
                        std::cout << " ";    
                        break;
                    }

                    default:
                    {
                        std::cout << " ";
                        break;
                    }
                }
            }

            std::cout << "\n";
        }

        std::cout << std::endl;
    }

private:
    symbol_code_t symbols_codes [SNAKE_CONST::MAX_VALUE_Y][SNAKE_CONST::MAX_VALUE_X];
};

#endif