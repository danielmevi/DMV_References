/* Using the C++ language, have the function  ABCheck(str) 
 * take the str parameter being passed and return the string 
 * true if the characters a and b are separated by exactly 3 
 * places anywhere in the string at least once 
 * (ie. "lane borrowed" would result in true because there 
 * is exactly three characters between a and b). 
 * Otherwise return the string false. 
 *
 * Input = "after badly"Output = "false" 
 * Input = "Laura sobs"Output = "true" 
*/

#include <iostream>
#include <string>

const std::string ABcheck( std::string str )
{
    for(std::string::iterator IT = str.begin(); IT != str.end(); ++IT)
        if( *IT == 'a' and *(IT+4) == 'b')
            return "true";
    
    return "false";

}

int main (const int argc, const char* const argv[])
{
    std::cout << ABcheck(argv[1]) << std::endl;
    return 1;
}
