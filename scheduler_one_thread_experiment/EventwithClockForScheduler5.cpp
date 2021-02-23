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
#include <cassert>





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
using Clock = std::chrono::steady_clock;
using event_timer_t = std::chrono::time_point<Clock>;
 
template <class Z>
struct Event {
    Event(Params P, int p, 
    std::chrono::milliseconds n,
    Z f) :
        params{P}, priority{p}, timeout{n},
        next_timeout{Clock::now() + timeout}, functor{f} {}

    void operator() () { functor(params); }

    void update_for_next_timeout() {
        next_timeout = Clock::now() + timeout;
    }

    Params params;

    int priority;
    std::chrono::milliseconds timeout;
    event_timer_t next_timeout;
    std::function<Z> functor;
};
template <class Z>
inline Event<Z> CreateEvent(Params P, int i, std::chrono::milliseconds t, Z& z){
    return Event<Z> {P, i, t, z};
}

template <class Z>
inline bool operator< (const Event<Z>& e1, const Event<Z>& e2) {
        return e1.next_timeout > e2.next_timeout;
}

//using EventQueue = std::priority_queue<Event<void(Params)>>;

// TEST
using EventQueue = std::vector<Event<void(Params)>>;

///////////////////////////////////////////////////////////////

EventQueue CreatePeriodicEventContainer(PDUs pdus){
    EventQueue event_priority_queue;

    // Queue should be filled in base of pdus
    // Params should be taken from somewhere else instead of creating new one
    using namespace std::chrono_literals;
    event_priority_queue.emplace_back(CreateEvent(Params{}, 1,
            10ms,
            foo1));

    event_priority_queue.emplace_back(CreateEvent(Params{}, 2,
            20ms,
            foo2));
    
    return event_priority_queue;
}



///////////////////////////////////////////////////////////////
// Client

int main() {
    using namespace std::chrono_literals;
    // Get JSON 
    auto pdus{ParsePdus(/*json value*/)};

    auto periodic_event_container{CreatePeriodicEventContainer(pdus)};
    //TEST
    std::cout << "Init\n";
    auto start = Clock::now();
        Clock::time_point dend;
        std::chrono::duration<double> diff = start-dend;
        std::cout << "NOW: " << diff.count() << '\n';
        std::for_each(begin(periodic_event_container),
                    end(periodic_event_container),
                    [](auto& e) { 
                        auto start = e.next_timeout;
                        Clock::time_point dend;
                        std::chrono::duration<double> diff = start-dend;
                        std::cout << e.priority << ": "
                                  << diff.count() << '\n';});
    std::cout << "Run\n";
    // This should be a configurable endless loop
    for(auto i{10}; i; --i) {
        //TEST
        std::cout << "IT: " << i << '\n';
        auto start = Clock::now();
        Clock::time_point dend;
        std::chrono::duration<double> diff = start-dend;
        std::cout << "NOW: " << diff.count() << '\n';
        std::for_each(begin(periodic_event_container),
                    end(periodic_event_container),
                    [](auto& e) { 
                        auto start = e.next_timeout;
                        Clock::time_point dend;
                        std::chrono::duration<double> diff = start-dend;
                        std::cout << e.priority << ": "
                                  << diff.count() << '\n';});


        assert(not periodic_event_container.empty());

        auto event{periodic_event_container.back()};

        if (event.next_timeout <= 
                Clock::now()){
            event();

            event.update_for_next_timeout();
            periodic_event_container.pop_back();
            periodic_event_container.push_back(event);
            std::sort(begin(periodic_event_container), end(periodic_event_container));
        }

        std::this_thread::sleep_for(100ms);
    }

}