<<<<<<< Updated upstream
#include <tr1/memory>
#include <iostream>

int main(const int, const char* const [])
{
    std::tr1::shared_ptr<int> A(new int(5));
    std::cout << *A << std::endl;
    return 1;
}
||||||| merged common ancestors
=======
#include <tr1/memory>
#include <iostream>
#include <tr1/functional>
#include <tr1/array>

int main( const int, const char* const [])
{
    std::tr1::function X;
    std::tr1::array<int,3> arr = {1,2,3};

    std::tr1::shared_ptr<int> A(new int(5));

    std::cout << *A << std::endl;

    return 1;
}
>>>>>>> Stashed changes
