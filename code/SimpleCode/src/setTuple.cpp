#include <iostream>
#include <utility>
#include <set>

int main(const int, const char* const [])
{
    auto comp = [](std::pair<int,uint64_t> arg1, std::pair<int,int> arg2)
    {
        return arg1.first < arg2.first;
    };

    std::set<std::pair<int,int>, decltype(comp)> S(comp);
    S.emplace(std::make_pair(1,2));
    S.emplace(std::make_pair(2,2));
    S.emplace(std::make_pair(3,2));
    S.emplace(std::make_pair(3,3));
 
    uint64_t N = 2;

    auto I = S.find(std::make_pair(3,NULL)); 
    if (I != S.end() and I->second == N) 
        std::cout << "found: " << I->second << '\n';

    std::cout << S.size() << '\n';
    for (auto&& i : S)
        std::cout << i.first << '-' << i.second << '\n';

    return 1;
}
