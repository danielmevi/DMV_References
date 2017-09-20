/*
 *
 */

#include <cstdint>
#include <type_traits>
#include <numeric>
#include <iterator>
#include <iostream>

template <typename...T>
uint32_t adder(T...values) {
  std::common_type_t<T...> array[sizeof...(T)]{values...};
  return std::accumulate(std::begin(array), std::end(array), 0);
}


// Testbench
int main(const int, const char*[])
{
  std::cout << adder(1,2,3,4,5) << '\n';
  return 0;
}