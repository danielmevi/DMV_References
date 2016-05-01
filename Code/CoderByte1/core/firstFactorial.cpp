/* Using the C++ language, have the function  FirstReverse(str) 
 * take the str parameter being passed and return the string 
 * in reversed order. 
*/

#include <iostream>
#include <cstdlib>

using namespace std;

const int factorial(const int factor)
{
   if( !factor )
      return 1;
   return factor * factorial(factor - 1);
}

int main(const int Argc, const char* const Argv[])
{
   const int factor = atoi(Argv[1]);

   cout << factorial(factor) << endl;

   return 1;
}
