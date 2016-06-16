#include <iostream>
#include <type_traits>
#include <iostream>
#include <cstdint>

//////////////////////////////////////////////////////
// User debug configuration
//////////////////////////////////////////////////////
static constexpr bool DEBUG = true;



//////////////////////////////////////////////////////
// Debug src
//////////////////////////////////////////////////////
const char* DEBUG_array_p [100];
unsigned DEBUG_timeStamp_p [100];
static unsigned char DEBUG_PC;


//////////////////////////////////////////////////////
// Library

// Aliases
//template< bool B >
//using bool_constant = std::integral_constant<bool,B>; 
//
//template< typename T >
//using remove_cv_t = typename  std::remove_cv<T>::type;
//
//using true_type = bool_constant<true>;
//using false_type = bool_constant<false>;
//
template< bool B, typename T = void >
using enable_if_t = typename std::enable_if<B,T>::type;
//
//template< typename T >
//struct type_is { using type = T; };

// Bases
//class Debug : public true_type{};
//class Production : public false_type {};

// Conditions
//template< typename T >
//using is_debug = std::is_same< remove_cv_t<T>, Debug>; // TODO: Why compiler mentions that it requires template arguments?
//
//template< bool, typename T, typename >
//struct IF : type_is<T> {};
//template< typename T, typename F >
//struct IF<false, T, F> : type_is<F> {};
//template< bool B, typename T, typename F >
//using IF_t = typename IF<B, T, F>::type;


//////////////////////////////////////////////////////
// src

void DEBUG_trace(unsigned payload) { DEBUG_timeStamp_p[DEBUG_PC] = payload; }
void DEBUG_trace(const char* payload) { DEBUG_array_p[DEBUG_PC] = payload; }

// TODO: Add variadic for several payloads of const char* and unsingned int
template< typename Q >
//enable_if_t< is_debug<T>::value > // TODO:  Not sure how to define template parameters to catch Device
enable_if_t< std::integral_constant<bool, DEBUG>::value > // TODO:  Not sure how to define template parameters to catch Device
TRACE( Q payload )
{
    DEBUG_trace(payload);
    ++DEBUG_PC;
}


//////////////////////////////////////////////////////
// User src code
//////////////////////////////////////////////////////
//class Device : public IF_t< DEBUG, Debug, Production >
class Device
{
    public:
        Device() {}

        std::string run_a()
        {
            std::string local("A_local)");
            std::string local_2("A_local2");
            std::swap(local, local_2);
            TRACE("Execution of process A"); // TODO: Not sure if this is right to pass Device type
            return local;
        }

        std::string run_b()
        {
            std::string local("A_local)");
            std::string local_2("A_local2");
            std::swap(local, local_2);
            TRACE("Execution of process B"); // TODO: Not sure if this is right to pass Device type
            return local;
        }
};




//////////////////////////////////////////////////////
// User main
//////////////////////////////////////////////////////

int main()
{
    Device dv;
    std::cout << dv.run_a() << std::endl;
    return 0;    
}
