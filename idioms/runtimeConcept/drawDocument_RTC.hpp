#include <iostream>
#include <string>
#include <vector>

namespace RTCidiom {

template <typename T>
void draw(const T& obj, std::ostream& out, size_t position) {
    out << std::string(position, ' ') << obj << '\n';
}

class object_t {
 public:
    template <typename T>
    object_t(T x) : self_(std::make_shared<model<T>>(std::move(x))) {}

    friend void draw(const object_t& x, std::ostream& out, size_t position) {
        x.self_->draw_(out, position);
    }

 private:
    struct concept_t {
        virtual ~concept_t() = default;
        virtual void draw_(std::ostream&, size_t) const = 0;
    };
    // PImpl
    template <typename T>
    struct model final : concept_t {
        model(T x) : data_(std::move(x)) {}
        virtual void draw_(std::ostream& out, size_t position) const override {
            draw(data_, out, position);
        }
        T data_;
    };
    std::shared_ptr<const concept_t> self_;
};

using document_t = std::vector<object_t>;

void draw(const document_t& doc, std::ostream& out, size_t position) {
    out << std::string(position, ' ') << "<document>\n";
    for (const auto& obj : doc) {
        draw(obj, out, position + 2);
    }
    out << std::string(position, ' ') << "/<document>\n";
}
}
