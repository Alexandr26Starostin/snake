#include <iostream>

enum class snake_error_t 
{
    NOT_ERROR = 0
};

int main ()
{
    return static_cast<int> (snake_error_t::NOT_ERROR);
}