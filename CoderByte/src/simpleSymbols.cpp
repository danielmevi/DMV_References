/* Using the C++ language, have the function  SimpleSymbols(str) 
 * take the str parameter being passed and determine if it is an 
 * acceptable sequence by either returning the std::string true or false. 
 * The str parameter will be composed of + and = symbols with several 
 * letters between them (ie. ++d+===+c++==a) and for the std::string to 
 * be true each letter must be surrounded by a + symbol. So the 
 * std::string to the left would be false. The std::string will not be empty 
 * and will have at least one letter.
 *
 * Input = "+d+=3=+s+"Output = "true" 
 * Input = "f++d+"Output = "false"
 * 
*/

#include <iostream>
#include <string>
#include <cctype>

const std::string SimpleSymbols( std::string str )
{
    for(std::string::iterator Istr = str.begin(); Istr != str.end(); ++Istr)
        if( isalpha(*Istr) )
            if( *(Istr + 1) != '+' or *(Istr - 1) != '+' )
                return "false";

    return "true";
}

int main (const int argc, const char* const argv[])
{
    if( std::string("true") == SimpleSymbols("+d+=3=+s+") &
            std::string("false") == SimpleSymbols("f++d+") )
        std::cout << "Correct" << std::endl;
    else
        std::cout << "Incorrect" << std::endl;

    return 1;
}
