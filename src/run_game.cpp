#include <iostream>
#include <termios.h>
#include <unistd.h>

#include "const.h"
#include "snake.h"
#include "view.h"
#include "model.h"
#include "run_game.h"

static void setCanonicalMode ();

//---------------------------------------------------------------------------------------------------------------------------------------------

static void setCanonicalMode () 
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

void run_game ()
{
    snake_t snake;

    code_position (__FILE__, __LINE__);
    snake.print_inf ();

    setCanonicalMode(); 
}