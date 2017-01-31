/* 
 * Slot proposal code
 *
 * C++11
 * TMP
 */

#include <vector>

// 
struct req
{
};
//
struct rsp
{
};
//
struct data
{
};

// Five types of slots
struct slotA {};
struct slotB {};
struct slotC {};
struct slotD {};
struct slotE {};

// Example of req queue
std::vector<req> vreq;
// Example of rsp queue
std::vector<rsp> vrsp;
// Example of data queue
std::vector<data> vdata;

class slot_functionability
{

    protected:

        void internal_process( slotA )
        {
        }
        void Internal_process( slotB )
        {
        }
        // oher internal_process

        std::vector<req> svreq;
        std::vector<rsp> svsrp;
        std::vector<data> svdata;
};

template< typename T >
struct slot : private slot_functionability
{
    using type = T;

    void process() { internal_process<this::type>(); }
};

void DPIsendReq ()
{
    vreq.emplace(vreq.begin());
}

void DPIproccess()
{
    if( !vreq.empty() )
        slot<slotA> slot1(std::move(vreq.front()));

 
    slot.process();
}


// Example of emulator
int main(const int, const char* [])
{
    DPIsendReq();
    DPIsendReq();
    DPIsendReq();

    DPIproccess();
}


