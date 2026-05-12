#ifndef CONST_H_
#define CONST_H_

#include <iostream>
#include <cstddef>
#include <assert.h>

//--------------------------------------------------------------------------------------
#define DARK_STYLE
#ifdef  DARK_STYLE
const char BLUE_FILE_LINE[]    = "\u001b[38;5;33m";
const char WHITE_USUAL_TEXT[]  = "\u001b[38;5;15m";
const char GREEN_LIGHT_SHAKE[] = "\u001b[38;5;46m";
const char PURPLE_INDEX[]      = "\u001b[38;5;171m";
const char DEFAULT_COLOR[]     = "\u001b[0m";
const char APPLE_COLOR[]       = "\u001b[38;5;196m";   //red
const char SNAKE_1_COLOR[]     = "\u001b[38;5;46m";    //green
const char SNAKE_2_COLOR[]     = "\u001b[38;5;227m";   //yellow
const char SNAKE_3_COLOR[]     = "\u001b[38;5;75m";    //blue
const char SNAKE_4_COLOR[]     = "\u001b[38;5;165m";   //purple
#endif
//--------------------------------------------------------------------------------------

namespace SNAKE_CONST { 
    const size_t MAX_VALUE_X       = 100;
    const size_t MAX_VALUE_Y       = 100;
    const size_t INIT_LENGTH_SNAKE = 3;
}

inline void code_position (const char* file, const int line)
{
    assert (file);

    std::cout << "\n-------------------------------------------------\n";
    std::cout << BLUE_FILE_LINE << file << ":" << line << WHITE_USUAL_TEXT;
    std::cout << "\n-------------------------------------------------\n" << std::endl;
}

enum class symbol_code_t
{
    CLEAR   = 0,
    APPLE   = 1,
    SNAKE_1 = 2,
    SNAKE_2 = 3,
    SNAKE_3 = 4,
    SNAKE_4 = 5
};

enum class direction_t
{
    UP    = 0,
    LEFT  = 1,
    RIGHT = 2,
    DOWN  = 3
};

#endif