/*
 *
 */

#include <iostream>

// Non-trivial constructor
struct Object {
    Object() { std::cout << __PRETTY_FUNCTION__ << '\n'; }
};

// C++17 variant is meant to replace unions for a type safer object
union MyUnion {
    int a;
    bool b;
    Object c;

    MyUnion() : c() {}
};

int main() {

    MyUnion theUnion;

    return 1;

}
