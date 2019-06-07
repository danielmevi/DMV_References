/*
 * This code demonstrate the implementation of the code header pImpl idiom.
 * This header represent the interface of an implementation defined in the source file.
 *
 * The Benefits of having the pImpl idiom implemented is that any user of the API class will not have to recompile
 * every time the implemetation changes in the API source. It is only required to do the linking process of the
 * compiler
 *
 * Notes:
 *  The API header file it is mean to be stable code that does not change much over time. Therefore any version of the
 *  API implementation will only be requiring customer linking of the code
 *
 */

#include <memory>

template <typename T>
using Pimpl = const std::unique_ptr<T>;

class API {
  public:
    API();
    ~API();

  private:
    class impl;
    Pimpl<impl> pImpl;
};
