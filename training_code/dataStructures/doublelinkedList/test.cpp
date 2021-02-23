#include "doublelinkedlist.h"

#include <fstream>


int main() {
    std::ifstream in("input.txt");

   int n, capacity,i;
   in >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      in >> command;
      if(command == "get") {
         int key;
         in >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         in >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
