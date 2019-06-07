#include <iostream>

class Base {
 private:
    static int A;

 public:
    int foo() { return ++A; }
};

int Base::A(0);

class Parent {
 private:
    Base b;

 public:
    int foo() { return b.foo(); }
};

int main(const int, const char* const[]) {
    Base a;
    std::cout << a.foo() << '\n';

    Parent P;
    std::cout << P.foo() << '\n';

    // std::cout << Base::A << '\n';

    return 1;
}
