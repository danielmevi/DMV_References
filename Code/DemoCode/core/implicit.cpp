/*
 * This excersice explain the use of the keyword implicit.
 * Explicit is a prototype function keyword which determines to the compiler to explicity use the 
 * object type that the function expects in his parameter.
 * Without the keyword the object can be created in the go with the constructor
 *
*/

#include <iostream>

class ObjectA 
{
   public:
      ObjectA() : member(0) {}
      ObjectA(const int argv) : member(argv) {}
      //explicit ObjectA(const int argv) : member(argv) {}
      ~ObjectA() {}
      const int Get() const{ return member; }
   private:
      const int member;
};

void Print( const ObjectA &Obj )
{
   std::cout << Obj.Get() << std::endl;
}

int main()
{
   ObjectA Obj(int(1));
   Print(5);
   return 1;
}
