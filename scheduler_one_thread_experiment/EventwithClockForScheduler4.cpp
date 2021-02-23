#include <queue>
#include <unordered_map>
#include <chrono>
#include <vector>
#include <string>
#include <chrono>
#include <iostream>
#include <functional>
#include <utility>
#include <algorithm>
#include <thread>





//////////////////////////////////////////////////////////////
// Configuration
struct SignalGroupMetadata {
    int id;
    std::chrono::milliseconds timeout;
    std::vector<std::string> signal_groups;
};


struct Configuration {
    SignalGroupMetadata SignalGroupContainers;
    // Other maps
};

struct Params {
    Params() = default;
    Configuration cfg;
    int id;
    // other containers
};

using PDUs = std::unordered_map<int, SignalGroupMetadata>;

//////////////////////////////////////////////////////////////
// JsonParser

PDUs ParsePdus() {
    PDUs pdus;
    // Populate pdus
    return pdus;
}


///////////////////////////////////////////////////////////////
///////// Function with different logics
void foo1(Params) {
    std::cout << "FOO1\n";
}
void foo2(Params) {
    std::cout << "FOO2\n";
}

//////// Event

template <class Y, class Z>
struct Event {
    Event(Params P, int p, 
    Y n,
    Z f) :
        params{P}, priority{p}, next_timeout{n}, functor{f} {}

    bool operator< (Event<Y, Z>&) {
        return true;
    }

    void operator() () { functor(params); }

    void update_for_next_timeout() {
        // TODO: Add correct operation to update next_timeout with 
        // correct timeout from JSON
        next_timeout = std::chrono::steady_clock::now();
    }

    Params params;

    int priority;
    Y next_timeout;
    // TODO: Add timeout from JSON member
    std::function<Z> functor;
};
template <class Y, class Z>
inline Event<Y, Z> CreateEvent(Params P, const int i, const Y& t, const Z& z){
    return Event<Y, Z> {P, i, t, z};
}


using EventQueue = std::priority_queue<
        Event<std::chrono::time_point<std::chrono::steady_clock>,
        void(Params)>>;

///////////////////////////////////////////////////////////////

EventQueue CreatePerioridEventContainer(PDUs pdus){
    EventQueue event_priority_queue;

    //TODO: Resolve how to correctly set the now

    event_priority_queue.emplace(CreateEvent(Params{}, 1,
            std::chrono::steady_clock::now(),
            foo1));

    event_priority_queue.emplace(CreateEvent(Params{}, 1,
            std::chrono::steady_clock::now(),
            foo2));
    
    return event_priority_queue;
}



///////////////////////////////////////////////////////////////
// Client

int main() {
    // Get JSON 
    auto pdus{ParsePdus(/*json value*/)};

    auto periodic_event_container{CreatePerioridEventContainer(pdus)};

    while (1) {
        while(not periodic_event_container.empty()){
            auto event{periodic_event_container.top()};
            if (event.next_timeout >= 
                std::chrono::steady_clock::now()){
                    event();

                    event.update_for_next_timeout();
                    periodic_event_container.pop();
                    periodic_event_container.push(event);
                }
        }

        std::this_thread::yield();
    }

}