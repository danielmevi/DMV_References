/*
 * This code demonstrate that environment variables can be passed to 
 * code at compilation time.
 *
 * The method to accomplish such thing is to provide the compiler the -D flag 
 * with the corresponding MACRO definition expected to have in code
 *
 * i.e.
 * g++ src/envvar.cpp -o envvar.o -DHOME=1 
 */


#include <iostream>


int main()
{
    std::cout << HOME << std::endl;

    return 1;
}
