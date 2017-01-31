/*
 * This file code domenstrate the GCC checks related to the hidding of overloaded virtual functions with gcc switch
 * -Woverloaded-virtual
 *
 * g++ -Woverloaded-virtual
 */

#include <iostream>

struct base
{
    virtual void foo() { std::cout << __PRETTY_FUNCTION__ << '\n'; }
    virtual void foo(int) { std::cout << __PRETTY_FUNCTION__ << '\n'; }
    virtual void foo(char) { std::cout << __PRETTY_FUNCTION__ << '\n'; }

    virtual ~base() {}
};

struct deriver : public base
{
#ifdef __OK__
    using base::foo;
#endif
    virtual void foo() { std::cout << __PRETTY_FUNCTION__ << '\n'; }
};

int main( const int, const char* [])
{
    deriver obj;
    obj.foo();

#ifdef __OK__
    obj.foo(1);
    obj.foo('a');
#endif
}

