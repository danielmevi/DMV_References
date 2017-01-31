/*
 * Type erasure idiom
 *
 * Virtual functions
 *
 * This idiom consist in taking templates implementation to runtime. Where in theory the template implementation cannot
 * be adapted, since templates instantiations should be completely known at compilation time.
 * But with this idiom, all instantiations and implementations are compiled and binded at runtime depending in the
 * type.
 * At the end, the type of the class will define the behavior depending on runtime decisions.
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

class Poly_ImpBase {
  public:
    virtual ~Poly_ImpBase() {}
    virtual int  foo1()       = 0;
    virtual void foo2(double) = 0;
};

template <class T>
class Poly_Imp : public Poly_ImpBase {
    // Friends are used to extend the interfaces of objects
    // to maintain the code like: swap(a,b)
    // For it, swap with the correct types should be an extension interface of
    // the type. So friends is the correct way to code it
    // And in this case, Poly is the extension interface
    friend class Poly;

    // data is just in case A and B holds separate information like size.
    // Otherwise data variable can be avoided
    T data;

    int foo1() override {
        std::cout << __PRETTY_FUNCTION__ << " --> size = " << data.size
                  << '\n';  // To use it like this
        std::cout << __PRETTY_FUNCTION__ << '\n';
        ABfoo();
    }
    void foo2(double) override { /* Generic code using data*/
    }

    void ABfoo();  // Specific code with class specialization
};

// Specific implementation
template <>
void Poly_Imp<A>::ABfoo() {
    std::cout << __PRETTY_FUNCTION__ << '\n';
}
template <>
void Poly_Imp<B>::ABfoo() {
    std::cout << __PRETTY_FUNCTION__ << '\n';
}

class Poly {
  public:
    template <class T>
    void set() {
        imp = new Poly_Imp<T>;
    }

    int  foo1() { return imp->foo1(); }
    void foo2(double x) { return imp->foo2(x); }

    Poly() : imp(nullptr) {}
    ~Poly() { delete imp; }

  private:
    Poly_ImpBase *imp;
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

