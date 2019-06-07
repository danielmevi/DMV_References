/* Using the C++ language, have the function  CheckNums(num1,num2) 
 * take both parameters being passed and return the string true if
 * num2 is greater than num1, otherwise return the string false. 
 * If the parameter values are equal to each other then return the string -1.
 *
 * Input = 3 & num2 = 122Output = "true" 
 * Input = 67 & num2 = 67Output = "-1" 
*/

#include <iostream>
#include <cstdlib>

int CheckNums(int num1, int num2)
{ 
    return num1 - num2? (num1 - num2) <= -1?true:false:-1;
}

int main ( const int argc, const char* const argv[] )
{
    std::cout << CheckNums(atoi(argv[1]), atoi(argv[2])) << std::endl;
    return 1;
}
