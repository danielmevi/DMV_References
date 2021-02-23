/*
 */

#include <algorithm>
#include <iostream>
#include <memory>
#include <unordered_map>
#include <utility>
#include <vector>

///////////////////////////////////////////////////////////////////////////////
// External entities
// Module Tracker
void Track1() { std::cout << "Tracker: track event 1\n"; }
void Track2() { std::cout << "Tracker: track event 2\n"; }
void Track3() { std::cout << "Tracker: track event 3\n"; }

// External Layer (Simulator)
void SendPacket() { std::cout << "Sim: Sending packet to Simulator\n"; }

// External Layer Logger (Simulator)
void SimLog(const char* const str) { std::cout << "Sim: " << str << '\n'; }

// Customer Layer
void Event2() { std::cout << "Custom: Customer execution on event2\n"; }

///////////////////////////////////////////////////////////////////////////////
// Module
void (*UpstreamPacket)();
void (*ModuleSimLog)(const char* const);
void (*EventCallback)();

void configure() {
    UpstreamPacket = SendPacket;
    ModuleSimLog = SimLog;
    EventCallback = Event2;
}

void foo1() {
    Track1();
    ModuleSimLog("foo1 for flow X");
    // Execution
    ModuleSimLog("foo1 for flow Y");
}

void foo2() {
    Track2();
    EventCallback();
    // Execution
    UpstreamPacket();
    // More Execution
    ModuleSimLog("foo2 for flow Q");
}

void foo3() {
    Track3();
    // Execution
}

///////////////////////////////////////////////////////////////////////////////
// A
// Module

enum class Tag { A1, A2, A3 };

namespace CallbackMgr {
using Logfun = void (*)(Tag);
using Eventfun = void (*)();
std::vector<Logfun> A_LogCallbacks;

std::unordered_map<Tag, std::vector<Eventfun>> EventCallbacks = {
    {Tag::A1, {}}, {Tag::A2, {}}, {Tag::A3, {}}};

void runLogCallbacks(Tag tag) {
    std::for_each(A_LogCallbacks.begin(), A_LogCallbacks.end(),
                  [&](Logfun callback) { callback(tag); });
}
void runEventCallbacks(Tag tag) {
    auto callbacks = EventCallbacks.at(tag);
    std::for_each(callbacks.begin(), callbacks.end(),
                  [&](Eventfun callback) { callback(); });
}

void registerLogCallback(Logfun callback) {
    A_LogCallbacks.emplace_back(callback);
}
void registerEventCallback(Tag tag, Eventfun callback) {
    EventCallbacks.at(tag).emplace_back(callback);
}
};

//////////////
// Tracker
void Tracker(Tag tag) {
    switch (tag) {
        case Tag::A1:
            std::cout << "Tracker: track event A1\n";
            break;
        case Tag::A2:
            std::cout << "Tracker: track event A2\n";
            break;
        case Tag::A3:
            std::cout << "Tracker: track event A3\n";
            break;
        default:
            std::cerr << "Tag error\n";
    }
}

//////////////
// Simulator
void SimLog(Tag tag) {
    switch (tag) {
        case Tag::A1:
            std::cout << "Sim: track event A1\n";
            break;
        case Tag::A2:
            std::cout << "Sim: track event A2\n";
            break;
        case Tag::A3:
            std::cout << "Sim: track event A3\n";
            break;
        default:
            std::cerr << "Tag error\n";
    }
}
void UpstreamPacketA() { std::cout << "Sim: Sending packet to Simulator\n"; }

/////////////
// Customer
void EventA2() { std::cout << "Custom: Customer execution on event2\n"; }

void configureA() {
    // This should be done due to configuration
    CallbackMgr::registerLogCallback(Tracker);

    // This should be done by Simulator
    CallbackMgr::registerLogCallback(SimLog);
    CallbackMgr::registerEventCallback(Tag::A1, UpstreamPacketA);

    // This should be done by Customer
    CallbackMgr::registerEventCallback(Tag::A2, EventA2);
}

void fooA1() {
    CallbackMgr::runLogCallbacks(Tag::A1);
    CallbackMgr::runEventCallbacks(Tag::A1);

    // Execution

    CallbackMgr::runLogCallbacks(Tag::A1);
    CallbackMgr::runEventCallbacks(Tag::A1);
}
void fooA2() {
    CallbackMgr::runLogCallbacks(Tag::A2);
    CallbackMgr::runEventCallbacks(Tag::A2);

    // Execution

    CallbackMgr::runLogCallbacks(Tag::A2);
    CallbackMgr::runEventCallbacks(Tag::A2);
}
void fooA3() {
    CallbackMgr::runLogCallbacks(Tag::A3);
    CallbackMgr::runEventCallbacks(Tag::A3);

    // Execution

    CallbackMgr::runLogCallbacks(Tag::A3);
    CallbackMgr::runEventCallbacks(Tag::A3);
}

int main() {
    std::cout << "No pattern\n";
    configure();
    foo1();
    foo2();
    foo3();

    std::cout << "cmd pattern\n";
    configureA();
    fooA1();
    fooA2();
    fooA3();
}
