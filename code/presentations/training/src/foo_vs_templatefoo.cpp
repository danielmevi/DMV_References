/*
 * This code demonstrate what happend when there is a function and a template function that can end up with the same
 * function prototype.
 *
 * In conclusion, the compiler prefer to call te standalone function over the template function unless the function
 * call explicitly indicates to call the template function
 */

#include <iostream>

void foo(int) { std::cout << "Standalone function: " << __PRETTY_FUNCTION__ << '\n'; }

template< typename T>
void foo(T) { std::cout << "template function: " <<__PRETTY_FUNCTION__ << '\n'; }


int main(const int, const char *[] )
{
    foo(1);
    return 1;
}

