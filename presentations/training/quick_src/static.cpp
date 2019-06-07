#include <iostream>


struct A {
    static int X;
};

int A::X = 0;

int main(const int, const char *[] )
{
    A* a = new A();
    A::X = 1;
    std::cout << a->X << '\n';
    delete a;
    std::cout << A::X << '\n';

    return 1;
}
