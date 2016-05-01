/* Using the C++ language, have the function  LetterCountI(str) 
 * take the str parameter being passed and return the first word
 * with the greatest number of repeated letters. For example: 
 * "Today, is the greatest day ever!" should return greatest
 * because it has 2 e's (and 2 t's) and it comes before ever
 * which also has 2 e's. If there are no words with repeating
 * letters return -1. Words will be separated by spaces. 
 *
 * Use the Parameter Testing feature in the box below to test
 * your code with different arguments. 
 *
 * Input = "Hello apple pie"Output = "Hello" 
 * Input = "No words"Output = -1 
 */

#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>

const std::string LetterCount( const std::string &str )
{
    std::map<std::string,int> letter;
    std::istringstream ss(str);
    std::string tmp_str;

    while( ss >> tmp_str )
    {
        int count = 0, cnt = 0;
        for(std::string::iterator it = tmp_str.begin(); 
                it != tmp_str.end(); ++it)
        {
            cnt = std::count( tmp_str.begin(), tmp_str.end(), *it );
            if( cnt > count ) 
                count = cnt;
        }
        letter[tmp_str] = count;
    }

    std::map<std::string,int>::iterator it_max = letter.begin();
    for(std::map<std::string,int>::iterator it = ++letter.begin();
            it != letter.end(); ++it)
        if( it->second >= it_max->second )
            it_max = it;

    return it_max->second? --it_max->second? it_max->first : "-1" : "-1";
}

int main (const int argc, const char* const argv[] )
{
    std::string cin;
    std::getline(std::cin, cin);
    std::cout << LetterCount( cin ) << std::endl;
    return 1;
}
