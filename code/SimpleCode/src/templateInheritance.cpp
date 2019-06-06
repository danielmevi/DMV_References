#include <iostream>

class A {};
class B {};

template < typename T >
class AB : public T {

};


void foo ( const A ) { std::cout << "A" << '\n'; }
void foo ( const B ) { std::cout << "B" << '\n'; }

int main (const int, const char* const [] )
{
    AB<A> a;

    foo( a );

    return 1;

}
