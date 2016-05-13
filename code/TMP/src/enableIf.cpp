#include <iostream>
#include <type_traits>

class A
{
    public:
        explicit A() : str(new std::string("Exist")) {}

        void print()
        {
            std::cout << *str << std::endl;
            delete str;
        }

    private:
        std::string* str;
};

int main()
{
    A a;
    a.print();
    return 0;    
}
