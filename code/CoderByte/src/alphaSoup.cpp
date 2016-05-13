/* Using the C++ language, have the function  AlphabetSoup(str)
 * take the str string parameter being passed and return the string 
 * with the letters in alphabetical order (ie. hello becomes ehllo).
 * Assume numbers and punctuation symbols will not be included in the string.
 *
 * Input = "coderbyte" Output = "bcdeeorty" 
 * Input = "hooplah" Output = "ahhloop" 
*/

#include <iostream>
#include <list>
#include <algorithm>

const std::string AlphabetSoup( std::string str )
{
    std::list<char> List(str.begin(), str.end());
    List.sort();
    std::string Str;
    for(std::list<char>::iterator It = List.begin(); It != List.end(); ++It)
        Str += *It;
    return Str;
}

const std::string AlphabetSoup2( std::string str )
{
    sort(str.begin(), str.end());
    return str;
}

int main (const int srgc, const char* const argv[])
{
    std::cout << AlphabetSoup(argv[1]) << std::endl;
    std::cout << AlphabetSoup2(argv[1]) << std::endl;
    return 1;
}
