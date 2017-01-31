#include <map>
#include <iostream>

int main( const int, const char* const [] )
{
  std::map<int, int> a;
  a.insert(std::make_pair(5,6));
  auto b = a[5];
  if(b) a[5] = b = 7;
  
  std::cout << b << '\n';
  std::cout << a[5] << '\n';

  return 1;
}
