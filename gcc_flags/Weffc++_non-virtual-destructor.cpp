/*
 * This code file describes the warnings that Weffc++ will bring up at
 * compilation time
 *
 * Usage:
 * g++ -Weffc++ file -o out.o
 */

#include <iostream>
#include <memory>

// -Wnon-virtual-dtor
// Included when Weffc++
class base {
 public:
    base() { std::cout << "base constructor" << '\n'; }
#ifdef __OK__
    virtual ~base() { std::cout << "base destructor" << '\n'; }
#else
    ~base() { std::cout << "base destructor" << '\n'; }
#endif

    virtual void foo() { std::cout << "base::foo" << '\n'; }
};
class derived : public base {
 public:
    derived() { std::cout << "derived constructor" << '\n'; }
    ~derived() { std::cout << "derived destructor" << '\n'; }

    virtual void foo() { std::cout << "derived::foo" << '\n'; }
};

int main(const int, const char* []) {
    base* pdev = new derived;
    delete pdev;
    return 1;
}
