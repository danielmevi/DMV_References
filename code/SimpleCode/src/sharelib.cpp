#include <iostream>
#include <dlfcn.h>
#include <string>
#include <inttypes.h>

using namespace std;

extern void check_pcu_bfm_flow_invoke(uint64_t, uint64_t, uint32_t); 

int main()
{
//    void* handler = dlopen("/nfs/site/disks/fm_vt_0073/work/dmedin2/sarvani_libs/with_shared/libemubuildtb.so", RTLD_GLOBAL | RTLD_LAZY);
//    if( handler == NULL )
//        throw underflow_error(dlerror());
//
//    dlerror();
//    typedef void(*callback_t)(uint64_t, uint64_t, uint32_t);
//    callback_t fn_callback = reinterpret_cast<callback_t>(dlsym( handler, "check_pcu_bfm_flow_invoke" ));
//
//    string error = dlerror();
//    if( !error.empty() )
//    {
//        cout << error << endl;
//        throw underflow_error(error);
//    }
//
//    fn_callback(0xAAAA, 0xFFFF, 0x1);

    check_pcu_bfm_flow_invoke(0x3, 0x2, 0x1);
    
    return 1;
}
