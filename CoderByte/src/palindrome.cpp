/* Using the C++ language, have the function Palindrome(str) 
 * take the str parameter being passed and return the string 
 * true if the parameter is a palindrome, (the string is the 
 * same forward as it is backward) otherwise return the string 
 * false. For example: "racecar" is also "racecar" backwards.
 * Punctuation and numbers will not be part of the string. 
 *
 * Input = "never odd or even"Output = "true"
 * Input = "eye"Output = "true"
*/

#include <string>
#include <iostream>
#include <algorithm>

const std::string Palindrome( std::string str )
{
    for( std::string::iterator ITbegin = str.begin(), ITend = --str.end();
           ITbegin < next(ITend);
            ++ITbegin, --ITend)
    {
        if( *ITbegin == ' ' ) ++ITbegin;
        if( *ITend == ' ' ) --ITend;
        if( *ITbegin != *ITend )
            return "false";
    }
    return "true";
}

const std::string Palindrome2( std::string str )
{
    str.erase(std::remove(str.begin(), str.end(), ' '),str.end());
    return str == std::string(str.rbegin(), str.rend())?"true":"false";
}

int main ( const int argc, const char* const argv[] )
{
    std::cout << Palindrome(argv[1]) << std::endl;
    std::cout << Palindrome2(argv[1]) << std::endl;
    return 0;
}
