/* Using the C++ language, have the function  ExOh(str) take the str parameter 
 * being passed and return the string true if there is an equal number of x's 
 * and o's, otherwise return the string false. Only these two letters will be 
 * entered in the string, no punctuation or numbers. For example: if str is 
 * "xooxxxxooxo" then the output should return false because there are 6 x's and 5 o's.
 *
 * Input = "xooxxo"Output = "true" 
 * Input = "x"Output = "false" 
 */

#include <string>
#include <iostream>

const std::string ExOh( std::string str )
{
    int cnt = 0;
    for( std::string::iterator It = str.begin(); It != str.end(); ++It) 
        if(*It == 'x') ++cnt;
        else if(*It == 'o') --cnt;
    return cnt?"false":"true";
}

int main (const int argc, const char* const argv[])
{
    std::cout << ExOh(argv[1]) << std::endl;
    return 1;
}
