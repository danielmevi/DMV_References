/* Using the C++ language, have the function  WordCount(str) 
 * take the str string parameter being passed and return the 
 * number of words the string contains (ie. "Never eat shredded
 * wheat" would return 4). Words will be separated by single spaces. 
 *
 * Input = "Hello World"Output = 2 
 * Input = "one 22 three"Output = 3 
*/

#include <iostream>
#include <string>
#include <sstream> 

const int WordCount(std::string str)
{
    int cnt = 0;
    std::stringstream ss(str);
    std::string str2;
    while( ss >> str2 )
        ++cnt;
    return cnt;
}

int main (const int argc, const char* const argv[])
{
    std::cout << WordCount(argv[1]) << std::endl;
    return 1;
}
