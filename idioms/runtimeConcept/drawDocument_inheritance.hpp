#include <iostream>
#include <memory>
#include <string>
#include <vector>

namespace inheritance {

struct object_t {
    virtual ~object_t() {}
    virtual void draw(std::ostream&, size_t) const = 0;
};

using document_t = std::vector<std::shared_ptr<object_t>>;

void draw(const document_t& doc, std::ostream& out, size_t position) {
    out << std::string(position, ' ') << "<document>\n";
    for (const auto& obj : doc) {
        obj->draw(out, position + 2);
    }
    out << std::string(position, ' ') << "/<document>\n";
}
}
