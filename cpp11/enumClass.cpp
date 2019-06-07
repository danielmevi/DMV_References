/*
 *
 */

#include <iostream>

enum class Types { A, B, C, D };

int main() {
    Types types = Types::A;

    if (types == 0) {
        std::cout << "zero\n";
    } else {
        std::cout << "not zero\n";
    }

    return 1;
}
