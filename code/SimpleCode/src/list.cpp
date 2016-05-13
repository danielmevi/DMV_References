#include <list>
#include <iostream>
 
int main()
{
    std::string str("casa");
    std::list<char> letters(str.begin(), str.end());
    if (!letters.empty()) {
        std::cout << "The last character is: " << letters.back() << '\n';
    }  
}
