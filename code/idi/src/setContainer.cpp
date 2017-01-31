#include <set>
#include <iostream>

class packet {
  public:
    packet(const int a, const int b, const int c) : A(a), B(b), C(c) {}
    bool operator<(const packet& arg) const { return A < arg.comp(); }
    bool operator>(const packet& arg) const { return A > arg.comp(); }
    bool comp() const { return A; }
  private:
    int A;
    int B;
    int C;
};

int main(const int, const char* const[]) {
    auto comp = [](const packet op1 ,const packet op2) { return op2.comp() > op1.comp(); };
    auto set = std::set<packet,decltype(comp)>(comp);

    set.emplace(5,2,4);

    std::cout << set.size() << '\n';
    auto it = set.begin();
    std::cout << it->comp() << '\n';

    return 1;
}
