/*
 * This code represent the API implementation that the API interface refers to with the unique_ptr.
 * The main point of the pImpl idiom falls in the unique pointer to a class declared within the API interface which
 * holds all the private members required for compuation of the API.
 *
 * Any change in the API implementation will only required to be compiled separately without the customer code and
 * without the linking stage of the compiler. And then just linked into the customer code without any compilation
 * stage.
 *
 *
 * Compilation:
 *  This code can be compiled without main for example purpose only "g++ -c src/pimpl.cpp -o bin/pimpl.o"
 */

#include "pimpl.hpp"
#include <iostream>

class API::impl {
    public:
        void foo() { std::cout << "API implementation with private member outside header scope " << _var << '\n'; }

    private:
        int _var = 1;
};

// C++14
API::API() : pImpl{std::make_unique<impl>()} { pImpl->foo(); }
// C++11
//API::API() : pimpl(new impl{}) { pimpl->foo(); }

API::~API() = default;
