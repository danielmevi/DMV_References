#include "drawDocument_RTC.hpp"
#include "drawDocument_inheritance.hpp"
#include "drawDocument_noIdiom.hpp"

#include <iostream>
#include <string>
#include <utility>

struct myClass final : inheritance::object_t {
    virtual void draw(std::ostream& cout, size_t position) const override {
        cout << std::string(position, ' ') << "myClass\n";
    }
};

struct myClass2 {};
void draw(const myClass2&, std::ostream& out, size_t position) {
    out << std::string(position, ' ') << "5\n";
}

int main() {
    noidiom::document_t document;
    document.emplace_back(0);
    document.emplace_back(1);
    document.emplace_back(2);
    document.emplace_back(3);

    noidiom::draw(document, std::cout, 0);

    inheritance::document_t document1;
    document1.emplace_back(std::make_unique<myClass>());
    // document1.emplace_back(0); // Compilation error, since int does not
    // inherit from inheritance::object_t

    inheritance::draw(document1, std::cout, 0);

    RTCidiom::document_t document2;
    document2.emplace_back(0);
    document2.emplace_back(std::string("one"));
    document2.emplace_back(2);
    document2.emplace_back(std::string("three"));
    document2.emplace_back(myClass2());
    document2.emplace_back(document2);

    RTCidiom::document_t document3;
    document2.emplace_back(std::string("six"));
    document2.emplace_back(7);

    document2.emplace_back(document3);

    RTCidiom::draw(document2, std::cout, 0);
}
