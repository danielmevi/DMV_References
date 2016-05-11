#include <iostream>

template<typename T>
class base
{
    public:
        static int A;
};

class derived1 : public base<derived1>
{
    
};

class derived2 : public base<derived2>
{
};

template<typename T>
int base<T>::A = 5;

int main()
{
    derived1 D1;
    derived1 D11;
    derived2 D2;

    std::cout << &D1.A << std::endl;
    std::cout << &D11.A << std::endl;
    std::cout << &D2.A << std::endl;

    D1.A = 0;

    std::cout << D1.A << std::endl;
    std::cout << D11.A << std::endl;
    std::cout << D2.A << std::endl;
    
    return 0;
}
