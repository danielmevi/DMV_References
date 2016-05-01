/* Using the C++ language, have the function  SimpleAdding(num)
 * add up all the numbers from 1 to num. For the test cases, 
 * the parameter num will be any number from 1 to 1000. 
 */

#include <iostream>
#include <cstdlib>

const unsigned int SimpleAdding(int num)
{
    for(int it = 1, tmp = num; it < tmp; ++it)
        num += it;
    return num;
}

const unsigned int SimpleAdding2(int num)
{
    for(int it = num-1; it != 0; --it)
        num += it;
    return num;
}

int main (const int argc, const char* const argv[])
{
    std::cout << SimpleAdding(atoi(argv[1])) << std::endl;
    std::cout << SimpleAdding2(atoi(argv[1])) << std::endl;
    return 0;

}
