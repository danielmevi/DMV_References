/*
 *
 */

#include <memory>

struct A {
    int a;
    int b;
};

A make_A(const int arg1, const int arg2) { return A{arg1, arg2}; }

int main() {
    auto a = 1;
    auto b = 5;

    auto thiA = make_A(1, 2);

    auto ptr = std::make_unique<int>(5);

    return 1;
}
