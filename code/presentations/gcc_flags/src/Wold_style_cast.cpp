/*
 * This file code demonstrate the warning that GCC provides for C-style casting
 *
 * -Wold-style-casting
 */

#include <iostream>

int main(const int, const char* [])
{
    char   A = 1;
    short  B = 2;
    double C = 3;
    int    D = 4;

#ifdef __OK__
    std::cout << static_cast<int>(A) << '\n'
              << static_cast<int>(B) << '\n'
              << static_cast<int>(C) << '\n'
              << static_cast<int>(D) << '\n'
              << static_cast<int>('c') << '\n';
#else
    std::cout << (int)A << '\n'
              << (int)B << '\n'
              << (int)C << '\n'
              << (int)D << '\n'
              << (int)'c' << '\n';
#endif

    return 1;
}
