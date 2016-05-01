/* Using the C++ language, have the function  TimeConvert(num) take
 * the num parameter being passed and return the number of hours and 
 * minutes the parameter converts to (ie. if num = 63 then the output
 * should be 1:3). Separate the number of hours and minutes with a colon
 *
 * Input = 126 Output = "2:6" 
 * Input = 45 Output = "0:45" 
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

/* Using C++11 capabilities */
const std::string TimeConvert2( const int min )
{

    std::string time = std::to_string(min/60);
    time += ':';
    time += std::to_string(min%60);
    return time;
}

const std::string TimeConvert( const int min )
{
    std::ostringstream time;
    time << min/60;
    time << ':';
    time <<  min%60;
    return time.str();
}


int main (const int argc, const char* const argv[])
{
    std::cout << TimeConvert(atoi(argv[1])) << std::endl;
    return 1;
}
