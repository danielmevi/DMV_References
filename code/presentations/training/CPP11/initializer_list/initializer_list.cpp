/*
 *
 */

#include <initializer_list>
#include <iostream>
#include <vector>

struct MyStruct {
  MyStruct(std::initializer_list<int> list) {
    a = *list.begin();
    b = *(list.begin() + 1);
  }

  int a;
  int b;
};

int main() {
  // C and POD struct initialization
  MyStruct myStruct = {1, 2};
  std::cout << myStruct.a << ' ' << myStruct.b << '\n';

  std::vector<int> myVector{1, 2, 3, 4, 5};
  for (auto& it : myVector) {
    std::cout << it << ' ';
  }
  std::cout << '\n';

  for (auto it : {1, 2, 3, 4, 5, 6}) {
    std::cout << it << ' ';
  }
  std::cout << '\n';

  return 1;
}

