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

#endif