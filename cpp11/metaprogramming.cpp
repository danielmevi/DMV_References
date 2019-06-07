/*
 *
 */

#include <iostream>

//////////////////////////////////////////////////////
template <unsigned n>
struct factorial {
    enum { value = n * factorial<n - 1>::value };
};
template <>
struct factorial<0> {
    enum { value = 1 };
};
//////////////////////////////////////////////////////

int main() {
    std::cout << factorial<9>::value << std::endl;

    return 1;
}
