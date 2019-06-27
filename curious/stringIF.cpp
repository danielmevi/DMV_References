#include <iostream>
#include <string>

const char* foo() { return "hello"; }

int main() {
    if (const auto str = foo()) {
        std::cout << str.c_str() << '\n';
    }
}
