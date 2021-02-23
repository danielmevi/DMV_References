#include <iostream>
#include <functional>
#include <vector>

/////////////////////////////////////////////
// Signal Manager
bool callback1_imp(int) {
    std::cout << __PRETTY_FUNCTION__ << '\n';
    return true;
}
bool callback2_imp(bool) {
    std::cout << __PRETTY_FUNCTION__ << '\n';
    return true;
}

/////////////////////////////////////////////
// MEE
bool callback3_imp() {
    std::cout << __PRETTY_FUNCTION__ << '\n';
    return true;
}

/////////////////////////////////////////////
// Event

struct Event{
    template <class Z>
    Event(Z f) : functor(f) {}

    bool operator()() {return functor();}
    std::function<bool(void)> functor;
};

int main(){
    /////////////////////////////////////////////
    // Signal Manager
    auto callback1_tmp = [](auto param) {return callback1_imp(param);};
    auto callback2_tmp = [](auto param) {return callback2_imp(param);};

    auto id1 = 1;
    auto id2 = 2;
    auto callback1 = std::bind(callback1_tmp, id1);
    auto callback2 = std::bind(callback2_tmp, id2);

    std::vector<Event> Queue1;

    Queue1.emplace_back(callback1);
    Queue1.emplace_back(callback2);

    for(auto& event : Queue1){
        event();
    }

    /////////////////////////////////////////////
    // MEE
    auto callback3 = []{return callback3_imp();};

    std::vector<Event> Queue2;

    Queue2.emplace_back(callback3);

    for(auto& event : Queue2){
        event();
    }

}