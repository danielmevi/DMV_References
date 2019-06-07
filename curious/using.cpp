/*
 * This program demosntrate what happend when two namespaces defines a variable
 * with the same name and the usage
 * defines using of both namespaces.The result ends up with ambiguoys
 * instantiation of the variable since both
 * declarations are accesible.
 */

#include <iostream>

namespace A {
int x = 0;
}

namespace B {
int x = 0;
}

int main(const int, const char* []) {
    using namespace A;
    using namespace B;

    std::cout << x << '\n';

    return 1;
}
