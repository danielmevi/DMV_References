#include <iostream>

int main()
{
    const char A[] = {"This is the test to copy..."};
    char B[128];

    for( unsigned i = 0; i < 128; ++i )
        if( A[i] != '\n' ) B[i] = A[i];

    std::cout << B << std::endl;

    return 1;
}
