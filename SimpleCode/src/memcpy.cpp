#include <iostream>
#include <cstring>

int main()
{
    const char text1[] = {"This is the first text"};
    char* text2 = new(char[20]);

    memcpy( text2, text1, sizeof(text1) );

    std::cout << text2 << std::endl;

    return 1;
}
