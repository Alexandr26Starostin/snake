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
    snake_t snake (symbol_code_t::SNAKE_1);

    #ifdef PRINT_LIST_SNAKE_INF_
    code_position (__FILE__, __LINE__);
    snake.print_inf ();
    #endif

    set_canonical_mode(); 

    view_t view;
    view.reset_symbols_codes ();
    view.print_symbols_codes ();
}