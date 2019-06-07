/*
 * This file code demonstrate the GCC checks executed regarding the
 * initialization order matching the declaration order
 *
 * -Wreorder  (included with -Wall)
 */

#include <iostream>

class base {
 public:
#ifdef __OK__
    base() : A(1), B(2), C(3), D(4) {}
#else
    base() : D(4), B(2), C(3), A(1) {}
#endif
    void print() { std::cout << A << B << C << D << '\n'; }

 private:
    int A;
    int B;
    int C;
    int D;
};

int main(const int, const char* []) {
    base obj;
    obj.print();

    return 1;
}
