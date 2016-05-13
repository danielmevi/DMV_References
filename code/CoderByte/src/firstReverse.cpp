/* Using the C++ language, have the function  FirstReverse(str)
 * take the str parameter being passed and return the string in reversed order. 
 */

#include <string>
#include <iostream>

const std::string FirstReverse( std::string str )
{
    return std::string(str.rbegin(), str.rend());
}

int main (const int argc, const char* const argv[] )
{
    std::cout << FirstReverse(argv[1]) << std::endl;
    return 1;
}
