/*
 * This file code demonstrate the warning of Weffc++ regarding the overloading
 * of &&, || or ,
 *
 * -Weffc++
 */

#include <iostream>

struct OBJ {
    int A;
    int B;

    OBJ operator&&(const OBJ& obj1) {
        OBJ tmp;
        tmp.A = obj1.A && B;
        return tmp;
    }

    OBJ operator||(const OBJ& obj1) {
        OBJ tmp;
        tmp.A = obj1.A || B;
        return tmp;
    }
};

int main(const int, const char* []) {
    OBJ obj1, obj2;

    OBJ obj3 = obj1 && obj2;
    OBJ obj4 = obj1 || obj2;

    std::cout << obj3.A << " " << obj4.A << '\n';

    return 1;
}
