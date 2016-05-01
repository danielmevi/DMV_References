/* Using the C++ language, have the function  ArrayAdditionI(arr)
 * take the array of numbers stored in arr and return the string 
 * true if any combination of numbers in the array can be added up
 * to equal the largest number in the array, otherwise return the
 * string false. For example: if arr contains [4, 6, 23, 10, 1, 3] 
 * the output should return true because 4 + 6 + 10 + 3 = 23.
 * The array will not be empty, will not contain all the same elements,
 * and may contain negative numbers. 
 *
 * Input = 5,7,16,1,2Output = "false" 
 * Input = 3,5,-1,8,12Output = "true" 
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <sstream>

const std::string ArrayAddition( std::list<int> &nums )
{
    int max;
    {
        std::list<int>::iterator it_max = std::max_element(nums.begin(),nums.end());
        max = *it_max;
        nums.erase(it_max);
    }
    do
    {
        for( std::list<int>::iterator it_end = nums.end(); it_end != nums.begin(); --it_end)
        {
            int sum = 0;
            for(std::list<int>::iterator it_begin = nums.begin(); it_begin != it_end; ++it_begin)
                sum += *it_begin;
            if( sum == max ) 
                return "true";
        }
    }while( std::next_permutation(nums.begin(), nums.end()) );
    
    return "false";
}

int main( const int argc, const char* const argv[] )
{
    std::string cin;
    std::getline(std::cin, cin);
    std::istringstream ss(cin);
    std::list<int> nums;
    int val;
    while( ss >> val )
        nums.push_back(val);
    std::cout << ArrayAddition(nums) << std::endl;
    return 1;
}

