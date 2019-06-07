#include <string>
#include <iostream>
#include <sstream>

int main( const int, const char* const [] )
{
    std::string S("9857858,48474,C2U_Request,0,00,94894,04948478489,0409404,04,,,404,,,");
    std::istringstream SS(S);

    std::string field;
    while (std::getline(SS, field, ',')) {
        std::cout << field << '\n';
    }

    return 0;
}
