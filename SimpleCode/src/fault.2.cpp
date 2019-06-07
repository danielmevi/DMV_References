#include <iostream>

int main ()
{
    int a = 0;
    int b = 5;

    throw std::bad_alloc();

    std::cout << a << std::endl;

    return 1;
}
