/*
 * This code demonstrate the existance of the implamentation capable to define class members as static and even with
 * it, get a different static object from each class instantiation.
 *
 * Curiously Recurrent Template pattern (CRTP) is the idiom implemented to achieve such thing
 *
 */

#include <iostream>

template< typename T >
struct Base {
    static int var;
};

template <typename T> int Base<T>::var(0);

struct Deriver1 : public Base<Deriver1> {};

struct Deriver2 : public Base<Deriver2> {};


int main (const int, const char *[] )
{
    Deriver1 D1;
    Deriver1 D3;
    Deriver2 D2;

    std::cout << &D1.var << '\n';
    std::cout << &D2.var << '\n';
    std::cout << &D3.var << '\n';

    return 0;
}
