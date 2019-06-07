#include <iostream>
#include <type_traits>

// FULL SPECIALIZATION EXAMPLE
template <typename T>
void foo(T) {
    std::cout << "primary foo template" << '\n';
}
template <>
void foo(int) {
    std::cout << "int foo specialization" << '\n';
}

// PARTIAL SPECIALIZATION EXAMPLE
template <typename T, typename Z, int I>
struct A {
    A() {
        std::cout << "Primary template A" << '\t';
        std::cout << __PRETTY_FUNCTION__ << '\n';
    }
};
template <typename T>
struct A<T, char, 10> {
    A() {
        std::cout << "Partial specialization template A" << '\t';
        std::cout << __PRETTY_FUNCTION__ << '\n';
    }
};
template <typename T, int I>
struct A<T, T, I> {
    A() {
        std::cout << "Partial specialization template A" << '\t';
        std::cout << __PRETTY_FUNCTION__ << '\n';
    }
};

int main(const int, const char* []) {
    foo('a');
    foo<char>('a');
    foo(1);
    foo<int>('a');

    A<int, short, 10> a;
    A<int, char, 10> b;
    A<double, double, 500> c;

    return 1;
}
