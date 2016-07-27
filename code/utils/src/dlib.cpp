#include <dlfcn.h>
#include <string>
#include <stdexcept>

template<typename T>
void dynamic_lib(T& hook_ptr, std::string lib, std::string func)
{
    void* handler = dlopen(lib.c_str(), RTLD_GLOBAL | RTLD_LAZY);
    if( handler == NULL )
        throw std::logic_error("ERROR: Shared library does not exist: " + lib);

    dlerror();
    hook_ptr = reinterpret_cast<T>(dlsym( handler, func.c_str() ));
    if( dlerror() != NULL )
        throw std::logic_error("ERROR: " + func + " function was not found at " + lib); 
    
}

