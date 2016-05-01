/* Using the C++ language, have the function  ArithGeo(arr) take the array of
 * numbers stored in arr and return the string "Arithmetic" if the sequence
 * follows an arithmetic pattern or return "Geometric" if it follows a geometric 
 * pattern. If the sequence doesn't follow either pattern return -1. An arithmetic 
 * sequence is one where the difference between each of the numbers is consistent, 
 * where as in a geometric sequence, each term after the first is multiplied
 * by some constant or common ratio. Arithmetic example: [2, 4, 6, 8] and
 * Geometric example: [2, 6, 18, 54]. Negative numbers may be entered as parameters,
 * 0 will not be entered, and no array will contain all the same elements. 
 *
 * Input = 5,10,15Output = "Arithmetic" 
 * Input = 2,4,16,24Output = -1 
*/

#include <string>
#include <array>
#include <iostream>
#include <cstdio>
#include <stdio.h>

const std::string ArithGeo( const int *const xArray, const int size )
{
    bool is_A = true, is_G = true;
    for( int i = 1, 
             arith = xArray[1] - xArray[0],
             geo = xArray[1] / xArray[0];
             i < size-1; ++i )
    {
        if( is_A and (xArray[i+1] - xArray[i]) != arith )
            is_A = false;
        if( is_G and (xArray[i+1] / xArray[i]) != geo)
            is_G = false;
        if( !is_A and !is_G )
            break;
    }
    return is_A?"Arithmetic":is_G?"Geometric":"-1";
}

int main (const int argc, const char* const argv[] )
{
    const int xArray[] = {2,4,16,24};
    std::cout << ArithGeo(xArray,sizeof(xArray)/sizeof(*xArray)) << std::endl;

    return 0;
}
