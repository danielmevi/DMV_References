#include <iostream>
#include <memory>
#include <vector>

#ifdef TEMPLATE
template <typename T>
std::shared_ptr<std::vector<T>> create(T) {
    std::shared_ptr<std::vector<T>> P;
    std::cout << __PRETTY_FUNCTION__ << '\n';
    return P;
}
#else
std::shared_ptr<std::vector<int>> create(int) {
    std::shared_ptr<std::vector<int>> P;
    std::cout << __PRETTY_FUNCTION__ << '\n';
    return P;
}
std::shared_ptr<std::vector<short>> create(short) {
    std::shared_ptr<std::vector<short>> P;
    std::cout << __PRETTY_FUNCTION__ << '\n';
    return P;
}
std::shared_ptr<std::vector<double>> create(double) {
    std::shared_ptr<std::vector<double>> P;
    std::cout << __PRETTY_FUNCTION__ << '\n';
    return P;
}
std::shared_ptr<std::vector<long long>> create(long long) {
    std::shared_ptr<std::vector<long long>> P;
    std::cout << __PRETTY_FUNCTION__ << '\n';
    return P;
}
#endif

int main(const int, const char* []) {
#ifdef TEMPLATE
    auto A = create<int>(1);
//    auto B = create<short>(1);
//    auto C = create<double>(1);
//    auto D = create<long long>(1);
#else
    auto A = create(1);
//    auto B = create(static_cast<short>(1));
//    auto C = create(static_cast<double>(1));
//    auto D = create(static_cast<long long>(1));
#endif

    return 1;
}
