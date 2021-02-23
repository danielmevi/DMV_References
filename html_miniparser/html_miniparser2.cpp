#include <unordered_map>
#include <string>
#include <vector>
#include <memory>
#include <utility>
#include <sstream>
#include <optional>
#include <variant>
#include <iostream>

struct Node;

struct Attribute {
    std::string const data{};
    std::string const type{};
    std::unique_ptr<Node> leaf{};
};

struct Node{
    std::unordered_map<std::string, Attribute> data{};
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
    auto const request {token_request->substr(delimiter_position+1)};
    *token_request = last_token;
    return {out, request};
}

int main() {

     int n, q;
    std::cin >> n >> q;

    std::vector<std::string> inputs;
    std::vector<std::string> requests;

    {
    std::string str;
    std::getline(std::cin, str);
    }
    
    for (auto it{0}; it != n; ++it){
        std::string str;
        std::getline(std::cin, str);
        inputs.emplace_back(str);
    }
    for (auto it{0}; it != q; ++it){
        std::string str;
        std::getline(std::cin, str);
        requests.emplace_back(str);
    }

    std::unique_ptr<Node> root{std::make_unique<Node>()};
    Node* current{nullptr};

    for (auto const & line : inputs){
        if (openTag(line)){
            if (!current){
                current = root.get();
            }

            // Add to handle more values each tag
            const auto tokens{parseInputs(line)};

            std::string const tag{tokens[0].begin()+1, tokens[0].end()};
            std::string const data{tokens[3].begin()+1,
                              tokens[3].end()-2};
            std::string const type{tokens[1]} ;          
       
            auto new_leaf {std::make_unique<Node>()};
            new_leaf->back = current;
            
            auto const it {current->data.emplace(tag, 
                    Attribute{data, type, std::move(new_leaf)})};
           
            current = it.first->second.leaf.get();
        } else {     
            current = current->back;
        }
    }
    
    for (auto const& line : requests){
        auto const [tokens, request] {parseRequest(line)};

        current = root.get();
        std::unordered_map<std::string, Attribute>::iterator it;

        for (auto const& tag : tokens){
            it = current->data.find(tag);
            if (it == current->data.end()){
                std::clog << "Not Found!\n";
                break;
            }
            current = it->second.leaf.get();
        }
        if (it == current->data.end()){
            continue;
        }

        if (it->second.type != request){
            std::clog << "Not Found!\n";
            continue;
        }
        std::clog << it->second.data << '\n';
    }

    return 0;
}