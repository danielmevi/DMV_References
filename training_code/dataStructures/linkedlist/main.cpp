#include <iostream>
#include <random>
#include "linked_list.hpp"

int main(const int, const char *const[]) {
    LinkedList list{};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    for (uint32_t i = 0; i < 1000000; ++i) list.push_back(dis(gen));

    std::cout << list.size() << '\n';

    return 1;
}
