#include <unordered_set>
#include <iostream>

struct A {
    ~A() { std::cout << __PRETTY_FUNCTION__ << '\n'; }
};

int main (const int, const char* const[] )
{
    std::unordered_set<A> a;
    A a1;
    A a2;
    a.insert(std::move(a1));
    a.erase(a.begin());

    return 1;
}
