/*
 * Type erasure idiom
 *
 * Function Pointers
 *
 * This idiom consist in taking templates implementation to runtime. Where in
 * theory the template implementation cannot
 * be adapted, since templates instantiations should be completely known at
 * compilation time.
 * But with this idiom, all instantiations and implementations are compiled and
 * binded at runtime depending in the
 * type.
 * At the end, the type of the class will define the behavior depending on
 * runtime decisions.
 *
 *
 */

#include <cstddef>
#include <iostream>

struct A {
    std::size_t size = 0;
};
struct B {
    std::size_t size = 1;
};

class Poly {
  public:
    template <class T>
    void set() {
        data      = new T;         // Erase T (stored as void*)
        foo1_p    = &foo1_imp<T>;  // Instantiate implementation of foo1 for T
        foo2_p    = &foo2_imp<T>;  // Instantiate implementation of foo2 for T
        destroy_p = &destroy_imp<T>;  // Instantiate destructor implementation
    }

    int  foo1() { return foo1_p(this); }
    void foo2(double x) { return foo2_p(this, x); }

    Poly() : data(nullptr) {}
    ~Poly() {
        if (data) destroy_p(this);
    }

  private:
    void* data;
    int (*foo1_p)(Poly* self);           // Indirection to foo1_imp instance
    void (*foo2_p)(Poly* self, double);  // Indirection to foo2_imp instance
    void (*destroy_p)(Poly* self);       // Indirection to destroy_imp instance

    template <class T>
    static int foo1_imp(Poly* self) {
        T* data = static_cast<T*>(self->data);  // Reverse erasure of T
        std::cout << __PRETTY_FUNCTION__ << "-->" << data->size << '\n';
        ABfoo(data);
        return 1;
    }

    template <class T>
    static void foo2_imp(Poly* self, double) {
        T* data = static_cast<T*>(self->data);  // Reverse erasure of T
        // generic code (can use data)
    }

    template <class T>
    static void destroy_imp(Poly* self) {
        delete static_cast<T*>(self->data);  // type-safe deletion
    }

    static void ABfoo(const A*) { std::cout << __PRETTY_FUNCTION__ << '\n'; }
    static void ABfoo(const B*) { std::cout << __PRETTY_FUNCTION__ << '\n'; }
};

int main() {
    Poly thePoly;
    bool a;
    std::cin >> a;

    if (a)
        thePoly.set<A>();
    else
        thePoly.set<B>();

    thePoly.foo1();
    thePoly.foo2(3.2);
}

