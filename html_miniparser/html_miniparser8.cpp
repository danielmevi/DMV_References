#include <unordered_map>
#include <string>
#include <vector>
#include <memory>
#include <utility>
#include <sstream>
#include <optional>
#include <variant>
#include <iostream>

std::vector<std::string> const inputs {"<tag1 value = \"HelloWorld\">",
                                 "<tag2 name = \"Name1\">",
                                 "</tag2>",
                                 "</tag1>"};

std::vector<std::string> const request {"tag1.tag2~name",
                                        "tag1~name",
                                        "tag1~value"};

struct Value {
    std::string const data{};
};
struct Name {
    std::string const data{};
};
struct NA {};

struct Node{
    std::unordered_map<std::string, 
        std::variant<Value, Name, NA>> data{};
    std::unique_ptr<Node> leaf{};
    Node* back{nullptr};
};

bool openTag(std::string const & str) {
    if (str[0] == '<' && str[1] == '/'){
        return false;
    }
    return true;
} 

std::vector<std::string> parseInputs(std::string const& in){
    std::istringstream ss{in};
    std::string str;
    std::vector<std::string> out;
    while(std::getline(ss, str, ' ')){
        out.emplace_back(str);
    }
    return out;
}

std::pair<std::vector<std::string>, std::string>
parseRequest(std::string const& in){
    std::istringstream ss{in};
    std::string str;
    std::vector<std::string> out;
    while(std::getline(ss, str, '.')){
        out.emplace_back(str);
    }
    auto const token_request = out.end()-1;
    auto const delimiter_position {token_request->find('~')};
    auto const last_token {token_request->substr(0, delimiter_position)};
    auto const request {token_request->substr(delimiter_position)};
    *token_request = last_token;
    return {out, request};
}

int main() {
    std::unique_ptr<Node> root{std::make_unique<Node>()};
    Node* current{nullptr};

    for (auto const & line : inputs){
        if (openTag(line)){
            if (!current){
                current = root.get();
            } else {
                current->leaf = std::make_unique<Node>();
                current->leaf->back = current;
                current = current->leaf.get();
            }

            const auto tokens{parseInputs(line)};

            std::string const tag{tokens[0].begin()+1, tokens[0].end()};
            std::string const data{tokens[3].begin()+1,
                              tokens[3].end()-2};            
            
            if (tokens[1] == "value"){
                current->data.emplace(tag, Value{data});
            } else if (tokens[1] == "name"){
                current->data.emplace(tag, Name{data});
            } else {
                current->data.emplace(tag, NA{});
            }
        } else {
            current = current->back;
        }
    }

    for (auto const& line : request){
        auto const [tokens, request] {parseRequest(line)};
        
    }

    return 1;
}