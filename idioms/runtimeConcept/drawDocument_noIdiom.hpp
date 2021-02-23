#include <iostream>
#include <string>
#include <vector>

namespace noidiom {

using object_t = int;

void draw(const object_t& obj, std::ostream& out, size_t position) {
    out << std::string(position, ' ') << obj << '\n';
}

using document_t = std::vector<object_t>;

void draw(const document_t& doc, std::ostream& out, size_t position) {
    out << std::string(position, ' ') << "<document>\n";
    for (const auto& obj : doc) {
        draw(obj, out, position + 2);
    }
    out << std::string(position, ' ') << "/<document>\n";
}
}
