/*
 * This code tries to experiment what really happends when running an empty base
 * function that will be overwritten in
 * the derived functions.
 *
 * Motivation: On real model the system compained about the undefined virtual
 * function. But I was not sure if there is
 * something in specific with the system of the languaje
 *
 */

#include <iostream>
#include <memory>

class base {
  protected:
    virtual void foo();
};
class deriver {
  public:
    void run() { foo(); }
  protected:
    virtual void foo() { std::cout << __PRETTY_FUNCTION__ << '\n'; }
};

int main(const int, const char* []) {

    std::shared_ptr<deriver> A;
    int in;
    std::cin >> in;
    if(in){
        A = std::make_shared<deriver>();
        A->run();
    }
    return 1;
}
