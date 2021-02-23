#include <iostream>
#include <functional>

bool foo1(int, double){
    std::cout << __PRETTY_FUNCTION__ << '\n';
    return true; 
}

bool foo2(int, int){
    std::cout << __PRETTY_FUNCTION__ << '\n'; 
    return false;
}

template <class T>
struct Event {
    Event(T callback) : callback_{reinterpret_cast<void*>(callback)} {}
    bool operator() () {
        using callback_t = bool(*)(int, double);
        callback_t callback = callback_t(callback_);
        callback(1,1.2);

        auto result = reinterpret_cast<T*>(callback_)(2,2.2);

        //auto callback2 = getCallback();

        return true;
    }
    void* callback_;
};
template <class T>
inline Event<T> CreateEvent(T& callback) {
    return Event<T>{callback};
}

int main() {
    auto event{CreateEvent(foo1)};
    event();
    auto event2{CreateEvent(foo2)};
    event2();

    
}