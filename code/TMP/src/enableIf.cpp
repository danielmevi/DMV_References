#include <iostream>
#include <type_traits>
#include <iostream>
#include <cstdint>

//////////////////////////////////////////////////////
// User debug configuration
//////////////////////////////////////////////////////
static constexpr bool DEBUG = false;



//////////////////////////////////////////////////////
// Debug src
//////////////////////////////////////////////////////
const char* DEBUG_array_p [100];
unsigned DEBUG_timeStamp_p [100];
static unsigned char DEBUG_PC;


//////////////////////////////////////////////////////
// Library

template< bool B, typename T = void >
using enable_if_t = typename std::enable_if<B,T>::type;

//////////////////////////////////////////////////////
// src

void DEBUG_trace(unsigned payload) { DEBUG_timeStamp_p[DEBUG_PC] = payload; }
void DEBUG_trace(const char* payload) { DEBUG_array_p[DEBUG_PC] = payload; }

// TODO: Add variadic for several payloads of const char* and unsingned int
template< typename Q >
enable_if_t< std::integral_constant<bool, DEBUG>::value > 
TRACE( Q payload )
{
    DEBUG_trace(payload);
    ++DEBUG_PC;
}


//////////////////////////////////////////////////////
// User src code
//////////////////////////////////////////////////////
class Device
{
    public:
        Device() {}

        std::string run_a()
        {
            std::string local("A_local)");
            std::string local_2("A_local2");
            std::swap(local, local_2);
            TRACE("Execution of process A");
            return local;
        }

        std::string run_b()
        {
            std::string local("A_local)");
            std::string local_2("A_local2");
            std::swap(local, local_2);
            TRACE("Execution of process B");
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
