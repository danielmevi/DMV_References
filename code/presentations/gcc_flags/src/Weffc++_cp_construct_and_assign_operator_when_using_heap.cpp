/*
 * Ths code file demostrate the GCC code check which warns about using objects
 * owning dinamyc memory allocated objects
 * without the definition of a copy constructor and assignment operator
 *
 * This check refers to rule of 3 for C++ and rule of 5 for C++11
 *
 * --Weffc++
 */

#include <string.h>
#include <iostream>

class base {
  public:
    base(const char* string) : _array(NULL)
    {
        if (string) {
            _array = new char[strlen(string) + 1];
            strcpy(_array, string);
        } else {
            _array  = new char[1];
            *_array = '\0';
        }
    }

    ~base() { delete[] _array; }

#ifdef __OK__
    base(const base& cpBase) : _array(NULL)
    {
        if (cpBase._array) {
            delete[] _array;
            _array = new char[strlen(cpBase._array) + 1];
            strcpy(_array, cpBase._array);
        } else {
            _array  = new char[1];
            *_array = '\0';
        }
    }

    base& operator=(const base& cpBase)
    {
        if (cpBase._array) {
            if (_array) {
                delete[] _array;
                _array = new char[strlen(cpBase._array) + 1];
            }
            strcpy(_array, cpBase._array);
        } else {
            _array  = new char[1];
            *_array = '\0';
        }
    }
#endif

    void print() { std::cout << _array << '\n'; }
  private:
    char* _array;
};

int main(const int, const char* [])
{
    base A("Hello");
    base B("World");
    base C = A;

    A.print();
    B.print();
    C.print();

    B = A;

    std::cout << "Final values" << '\n';

    A.print();
    B.print();
    C.print();

    return 1;
}
