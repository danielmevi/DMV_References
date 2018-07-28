/*
 *
 */

#include <iostream>

int main(){

    bool T = true;

    const auto integer = [&](){
        int a = 5;
        if (T){
            return ++a;
        } else {
            return --a;
        }
    }();

    const int A = 5;

    const auto integer1 = [T, A]() -> int {
        if (T){
            return A + 1;
        } else {
            return A - 1;
        }
    }();


    std::cout << integer << ' ' << integer1 << '\n';


    auto F = [](const bool sel){
        return sel? 10 : 20;
    };

    std::cout<< F(T) << '\n';


    return 1;
}
