/*
 *
 */

#include <iostream>

struct MyClass {
    MyClass() = default;
    MyClass(const MyClass&) = default;
    MyClass(MyClass&&) = default;
    MyClass& operator=(const MyClass&) = default;
    MyClass& operator=(MyClass&&) = default;
};

void foo(const MyClass) { std::cout << __PRETTY_FUNCTION__ << '\n'; }
void foo1(const MyClass&) { std::cout << __PRETTY_FUNCTION__ << '\n'; }
void foo2(const MyClass&&) { std::cout << __PRETTY_FUNCTION__ << '\n'; }

int main(const int, const char* const[]) {
    MyClass myclass;

    foo(myclass);
    foo1(myclass);
    foo2(std::move(myclass));

    return 1;
}
