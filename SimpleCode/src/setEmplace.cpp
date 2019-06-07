#include <iostream>
#include <list>
#include <vector>
#include <string>

struct A {
    A(int a) : val(a) {}
    ~A() { std::cout << "destructor\n";}
    int  get() const { return val; }
    void kill() { this->~A(); }
    private:
    int val;
};

int main(const int, const char* const[]) {
    std::list<A> list;
    std::list<A>::iterator it;

    list.emplace_back(1);
    it = --list.end();
    std::cout << it->get() << '\n';
    list.emplace_back(2);
    it = --list.end();
    std::cout << it->get() << '\n';
    list.emplace_back(3);
    it = --list.end();
    std::cout << it->get() << '\n';

    std::cout << list.size() << '\n';
    list.begin()->kill();
    std::cout << list.size() << '\n';

    for(auto& item : list) {
        std::cout << item.get() << '\n';
    }


    std::vector<std::string> V;
    V.push_back("1");
    V.push_back("2");
    V.push_back("3");
    V.push_back("4");
    std::cout << V.size() << '\n';

    return 0;
}
