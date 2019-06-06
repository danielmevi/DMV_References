/*
 * Code example to demostrate the use of using a type to implement polimorphism
 * on an object
 */
#include <iostream>
#include <type_traits>

struct SlotA {
};
struct SlotB {
};
struct SlotC {
};

template <typename T>
struct Slot {
  public:
    void process() { _process<T>(); }
  private:
    template <typename U>
    typename std::enable_if<std::is_same<U,SlotA>::value>::type _process()
    {
        std::cout << __PRETTY_FUNCTION__ << "\n\n";
        return;
    }

    template <typename U>
    typename std::enable_if<std::is_same<U,SlotB>::value>::type _process()
    {
        std::cout << __PRETTY_FUNCTION__ << "\n\n";
        return;
    }

    template <typename U>
    typename std::enable_if<std::is_same<U,SlotC>::value>::type _process()
    {
        std::cout << __PRETTY_FUNCTION__ << "\n\n";
        return;
    }
};

int main(const int, const char* [])
{
    Slot<SlotA> slot1;
    Slot<SlotB> slot2;
    Slot<SlotC> slot3;

    slot1.process();
    slot2.process();
    slot3.process();
}
