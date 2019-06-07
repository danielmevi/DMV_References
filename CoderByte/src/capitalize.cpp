/* Using the C++ language, have the function  LetterCapitalize(str)
 * take the str parameter being passed and capitalize the first letter 
 * of each word. Words will be separated by only one space. 
 *
 * Input = "hello world"Output = "Hello World" 
 * Input = "i ran there"Output = "I Ran There" 
*/

#include <string>
#include <iostream>
#include <cctype>

const std::string Capitalize( std::string str )
{
    bool cap = true;
    for( std::string::iterator letter = str.begin(); letter != str.end(); ++letter ) 
        if( cap )
        {
            *letter = toupper(*letter);
            cap = false;
        }
        else if( *letter == 0x20 )
            cap = true;

    return str;
}

int main( const int argc, const char* const argv[] )
{
    std::cout << Capitalize(argv[1]) << std::endl;
    return 1;
}
