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
        for (size_t y_index = 0; y_index < SNAKE_CONST::MAX_VALUE_Y; y_index++)
        {
            for (size_t x_index = 0; x_index < SNAKE_CONST::MAX_VALUE_X; x_index++)
            {
                symbols_codes[y_index][x_index] = symbol_code_t::CLEAR;
            }
        }
    } 

    void print_snake_in_symbols_code ()
    {
        
    }

private:
    symbol_code_t symbols_codes [SNAKE_CONST::MAX_VALUE_Y][SNAKE_CONST::MAX_VALUE_X];
};

#endif