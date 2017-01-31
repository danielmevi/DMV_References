#include <iostream>

int main()
{
#if !defined A || defined B || defined C
  std::cout << "HERE" << std::endl;
#endif

  return 0;
}
