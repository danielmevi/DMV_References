#include <iostream>
#include <dlfcn.h>

int main()
{
    std::string name("/nfs/site/disks/fm_vt_0073/work/dmedin2/callback_tmp/pcu_lib.so:callback_foo");

    std::string::size_type point = name.find(":");
    if( point == std::string::npos )
    {
        std::cout << "Not found" << std::endl;
        return 1;
    }

    std::string func(name, ++point, name.length() - 1);
    std::string lib(name, 0, --point);

    std::cout << lib << std::endl << func << std::endl;

    void* handler = dlopen(lib.c_str(), RTLD_GLOBAL | RTLD_LAZY);
    if( handler == NULL )
    {
        std::cout << dlerror() << std::endl;
        return 1;
    }

    typedef void (*callback_fn_t)(int*);

    dlerror();
    callback_fn_t _upstreamHook;
    _upstreamHook = reinterpret_cast<callback_fn_t>(dlsym( handler, func.c_str()));
    if( dlerror() != NULL )
    {
        std::cout << dlerror() << std::endl;
        return 1;
    }

    _upstreamHook( NULL );

    return 0;
    
}
