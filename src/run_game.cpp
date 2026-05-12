#include <iostream>

#include "const.h"
#include "snake.h"
#include "view.h"
#include "model.h"
#include "run_game.h"

//#define PRINT_LIST_SNAKE_INF_

//---------------------------------------------------------------------------------------------------------------------------------------------

void run_game ()
{
    snake_t snake;

    #ifdef PRINT_LIST_SNAKE_INF_
    code_position (__FILE__, __LINE__);
    snake.print_inf ();
    #endif

    set_canonical_mode(); 
}