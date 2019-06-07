/*
 * This file code demostrate the compilation warning for returning refference
 * when should return a value instead
 *
 * -Weffc++
 *
 */

#include <iostream>

class base {
 public:
    base() : A(0), B(0) {}
    base(const int a, const int b) : A(a), B(b) {}
    void print() { std::cout << A << ' ' << B << '\n'; }

    int A, B;

#ifdef __OK__
    friend const base operator*(const base& a, const base& b) {
        return base(a.A * b.A, a.B * b.B);
    }
#elif __LOCAL__
    friend const base& operator*(const base& a, const base& b) {
        base obj(a.A * b.A, a.B * b.B);
        return obj;
    }
#elif __NEW__
    friend const base& operator*(const base& a, const base& b) {
        base* obj = new base(a.A * b.A, a.B * b.B);
        return *obj;
    }
#elif __STATIC___
    friend const base& operator*(const base& a, const base& b);
#endif
};

#ifdef __STATIC__
const base& operator*(const base& a, const base& b) {
    static base obj{};
    obj.A = a.A * b.A;
    obj.B = a.B * b.B;
    return obj;
}
#endif

int main(const int, const char* []) {
    base a(1, 2), b(3, 4);
    base c = a * b;
    c.print();

    return 1;
}
