/*
 * Thi is the code that represents the software customer of the pImpl library
 * API.
 * One of the points of pImpl idiom is to create a firewall compilation between
 * the API implementation and their
 * customer usages.
 *
 * To demonstrate above paragraph, the compilation should be as followed.
 *
 * Compile API pImpl idiom:
 * g++ -c src/pImpl/pimpl.cpp -o bin/pimpl.o
 *
 * Compile API customer usage (main)
 * g++ -c src/pImpl/pimplMain.cpp -o bin/main.o
 *
 * Link two binaries
 * g++ bin/main.o bin/pimpl.o -o bin/exec.o
 *
 * Demonstration:
 * Any change done in pimpl.cpp would not require to recompile pimplMain.cpp. It
 * will only require to execute the link
 * stage with the compiler.
 *
 * Benefits:
 * Redure the compilation dependencies and compilation time, since pimpl codes
 * maintain their ABI if the header remains
 * without changes.
 * Very good implementation for libraries like the idi BFM
 *
 */

#include "pimpl.hpp"

int main(const int, const char* const[]) {
    API api;

    return 1;
}
