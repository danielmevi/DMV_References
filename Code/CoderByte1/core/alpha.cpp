/* parameter being passed and modify it using the following algorithm. Replace 
 * every letter in the string with the letter following it in the alphabet 
 * (<B>ie.</B> c becomes d, z becomes a). Then capitalize every vowel in this new 
 * string (a, e, i, o, u) and finally return this modified string. 
 */
#include <iostream>
#include <string>
#include <cctype>
#include <set>

const std::string alpha ( std::string str)
{
    const std::string vowels("aeiou");
    std::set<char> vowel(vowels.begin(),vowels.end());

    std::string newStr;

    for( std::string::iterator Istr = str.begin(); Istr != str.end(); ++Istr )
        if( isalpha(*Istr) )
        {
            /* Go to next alphabet string */
            *Istr = *Istr + 0x1;
            /* Char is vowel? */
            if( vowel.end() != vowel.find(*Istr) )
                /* Capitalize vowel */
                newStr += *Istr - 0x20;
            else
                newStr += *Istr;
        }
        else
            newStr += *Istr;


    return newStr;
}

int main (const int argc, const char* const argv[])
{
    std::cout << alpha(std::string(argv[1])) << std::endl;
    return 0;
}
