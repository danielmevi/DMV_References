/* Using the C++ language, have the function  VowelCount(str) 
 * take the str string parameter being passed and return the
 * number of vowels the string contains (ie. "All cows eat 
 * grass" would return 5). Do not count y as a vowel for this challenge.
 *
 *
 * Input = "hello"Output = 2 
 * Input = "coderbyte"Output = 3
*/

#include <iostream>
#include <string>
#include <set>
#include <cctype>

const int VowelCount( std::string str )
{
    std::set<char> vowel{'a','e','i','o','u'};
    int cnt = 0;
    for( std::string::iterator IT = str.begin(); IT != str.end(); ++IT )
        if( vowel.end() != vowel.find(tolower(*IT)) )
            ++cnt;
    return cnt;
}

int main (const int argc, const char* const argv[])
{
    std::cout << VowelCount(argv[1]) << std::endl;
    return 1;
}
