/* Using the C++ language, have the function  SecondGreatLow(arr) take the
 * array of numbers stored in arr and return the second lowest and second 
 * greatest numbers, respectively, separated by a space. For example: if arr
 * contains [7, 7, 12, 98, 106] the output should be 12 98. The array will
 * not be empty and will contain at least 2 numbers. It can get tricky if 
 * there's just two numbers! 
 * 
 * Use the Parameter Testing feature in the box below to test your code with different arguments. 
 *
 * Input = 1, 42, 42, 180Output = "42 42" 
 * Input = 4, 90Output = "90 4" 
*/

#include <iostream>
#include <string>
#include <list>

const std::string SecondGreatLow( std::list<int> &nums )
{
}

int main (const int agc, const char* const argv[])
{
    std::string cin;
    std::getline(std::cin, cin);
    std::istringstream ss(cin);
    std::list<int> nums;
    int val;
    while( ss >> val )
        nums.push_back(val);
    std::cout << SecondGeatLow(nums) << std::endl;
    return 1;
}
