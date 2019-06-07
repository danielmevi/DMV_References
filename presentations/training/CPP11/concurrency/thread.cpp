/*
 *
 */

#include <thread>
#include <iostream>
#include <cstdio>
#include <mutex>
#include <string>


struct sfoo {
    void operator()(const int val) {
        std::cout << "Thread :" << val << '\n';
    }
};

std::mutex myMutex;

void critical_foo(const std::string& str){
    myMutex.lock();
    std::cout << str;
    myMutex.unlock();
}

void critical_foo1(const std::string& str){
    std::lock_guard<std::mutex> guard(myMutex);
    std::cout << str;
}


int main(){

    int cnt = 0;

    auto foo = [&](const int val) { std::cout << "Thread : " << val << '\n'; };

    std::thread t1{foo, 1};
    std::thread t2{sfoo(), 2};

    t1.join();
    t2.join();

    std::thread t3{foo, 3};
    std::thread t4{std::move(t3)};

    t4.join();

    std::thread t5{critical_foo, "thread1\n"};
    std::thread t6{critical_foo, "thread2\n"};
    std::string str = "thread3\n";
    std::string str1 = "thread4\n";
    std::thread t7{critical_foo1, std::ref(str)};
    std::thread t8{critical_foo1, std::move(str1)};

    t5.join();
    t6.join();
    t7.join();
    t8.join();

    std::puts("Finish...");
    
    // try_lock
    // unique_lock
    // guard_lock
    
    // async
    // future
    // promise

    return 1;
}
