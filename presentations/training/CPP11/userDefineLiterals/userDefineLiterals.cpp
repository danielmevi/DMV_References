/*
 *
 */

#include <iostream>
 
constexpr long double operator"" _deg ( long double deg )
{
    return deg*3.141592/180;
}


int main() {
    double value = 90_deg;
    std::cout << value << '\n';

}
