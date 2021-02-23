#include <unordered_map>
#include <string>
#include <vector>
#include <memory>
#include <utility>
#include <sstream>
#include <optional>
#include <variant>
#include <iostream>
#include <cassert>

struct Node;

struct Attribute {
    std::unordered_map<std::string, std::string> const data;
    std::unique_ptr<Node> leaf{};
};

struct Node{
    std::unordered_map<std::string, Attribute> attribute{};
    Node* back{nullptr};
};

bool openTag(std::string const & str) {
    if (str[0] == '<' && str[1] == '/'){
        return false;
    }
    return true;
} 

std::pair<
std::string,
std::unordered_map<std::string, std::string>>
                     parseInputs(std::string const& in){
    assert(!in.empty());

    std::stringstream ss{in};
    std::string str;
    ss >> str;
    
    auto const offset {*(str.end()-1) == '>' ? 1 : 0};
    auto const tag {std::string(str.begin()+1, str.end() - offset)};

    std::unordered_map<std::string, std::string> out;
    std::pair<std::string, std::string> tmp;
    auto flag {0};
    while(ss >> str) {
        switch (flag){
            case 0:
                tmp.first = str;
                flag = 1;
                break;
            case 1: 
                flag = 2;
                break;
            case 2:
                tmp.second = str;
                const auto offset {*(str.end()-1) == '>'? 2 : 1};
                tmp.second = {str.begin()+1, str.end()-offset};
                out.emplace(move(tmp));
                flag = 0;
                break;
        }
    }

    assert(!tag.empty());
    return {tag, out};
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

    assert(!inputs.empty());
    assert(!requests.empty());

    std::unique_ptr<Node> root{std::make_unique<Node>()};
    Node* current{nullptr};

    for (auto const & line : inputs){
        if (openTag(line)){
            if (!current){
                current = root.get();
            }

            auto const [tag, attributes] {parseInputs(line)};         
       
            auto new_leaf {std::make_unique<Node>()};
            new_leaf->back = current;
            
            auto const it {current->attribute.emplace(tag, 
                    Attribute{attributes, std::move(new_leaf)})};
           
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
            it = current->attribute.find(tag);
            if (it == current->attribute.end()){
                std::cout << "Not Found!\n";
                break;
            }
            current = it->second.leaf.get();
        }
        if (it == current->attribute.end()){
            continue;
        }

        if (auto const found {it->second.data.find(request)}; 
                found == it->second.data.end() ){
            std::cout << "Not Found!\n";
            continue;
        } else {
            std::cout << found->second << '\n';
        }
    }

    return 0;
}