#include <tr1/memory>
#include <iostream>

int main(const int, const char* const [])
{
    std::tr1::shared_ptr<int> A(new int(5));
    std::cout << *A << std::endl;
    return 1;
}
