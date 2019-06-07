/*
 *
 */

#include <iostream>

// C++11 requires to have everythin in a single return statement
// C++14 allows flexibility on return statements and if statements
// C++17 allows array[x] sintax and loop staetments
constexpr int factorial(const int N) {
    return N <= 1 ? 1 : (N * factorial(N - 1));
}

int main() {
    std::cout << factorial(10) << '\n';

    return 1;
}
