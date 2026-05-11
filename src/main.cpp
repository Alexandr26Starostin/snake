#include <iostream>

#include "run_game.h"

enum class snake_error_t 
{
    NOT_ERROR  = 0,
    HAVE_ERROR = 1
};

//---------------------------------------------------------------------------------

int main ()
{
    snake_error_t status = snake_error_t::NOT_ERROR;

    run_game ();

    return static_cast<int> (status);
}