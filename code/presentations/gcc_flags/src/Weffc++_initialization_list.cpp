/*
 * This file code explains the compilation check about prefering initialization
 * to assignment constructors from Weffc++
 *
 * -Weefc++
 *
 */

#include <iostream>
#include <vector>

class base {
  public:
    // Initialiation constructor
#ifdef __OK__
    base() : A(0), B(1), Vec{1} {}
#else
    // Assignment constructor
    base()
    {
        A = 0;
        B = 1;
        Vec.emplace(Vec.begin(), 1);
    }
#endif

    int print() const { return *Vec.begin(); }
  private:
    int              A;
    int              B;
    std::vector<int> Vec;
};

int main(const int, const char* [])
{
    base b;
    std::cout << b.print() << '\n';
    return 1;
}
