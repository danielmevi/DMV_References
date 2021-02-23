#include <chrono>
#include <iostream>
#include <queue>
#include <functional>
#include <utility>
#include <algorithm>


///////////////////////////////////////////////////////////////////////////
struct Params {
    Params() = default;
    int Configuration;
    int Pducontainers;
    int SignalGroupContainers;
};

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

    void operator() () { functor(params); }

    Params params;

    int priority;
    Y next_timeout;
    std::function<Z> functor;
};
template <class Y, class Z>
Event<Y, Z> CreateEvent(Params P, const int i, const Y& t, const Z& z){
    return Event<Y, Z> {P, i, t, z};
}


////////////////////////////////////////////////////////////////

int main() {
    std::vector<
        Event<std::chrono::time_point<std::chrono::steady_clock>,
        void(Params)>> queue;

    queue.emplace_back(CreateEvent(Params{}, 1,
            std::chrono::steady_clock::now(),
            foo1));

    queue.emplace_back(CreateEvent(Params{}, 1,
            std::chrono::steady_clock::now(),
            foo2));

    for_each(begin(queue), end(queue), [](auto e) { e(); });

}



