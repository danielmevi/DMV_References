/*
 * This file code describes the compile check regarding returning *this for
 * operator= instead of other pointer
 *
 * -Weffc++
 */

#include <iostream>
#include <string>

class base {
 public:
    base(const std::string str) : _str(str) {}
#ifdef __OK__
    base& operator=(const base&) { return *this; }
#else
    base* operator=(const base&) { return this; }
#endif
    // Warning: The following code will return a copy of this
    // base operator=(const base&) { return this; }

    void print() { std::cout << _str << '\n'; }

 private:
    std::string _str;
};

int main(const int, const char* []) {
    base A{"A"};
    base B{"B"};
#ifdef __OK__
    (A = B).print();
#else
    (A = B)->print();
#endif

    return 1;
}
