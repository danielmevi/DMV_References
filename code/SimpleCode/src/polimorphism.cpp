#include <iostream>

class Base
{
  public:
    Base() { std::cout << "Base\n"; }
    void foo() { std::cout << "Base::foo\n"; }
    void foo(int) { std::cout << "Base::foo(int)\n"; }
};

class Derived1 : public Base
{
  public:
    Derived1() { std::cout << "Derived1\n"; }
    void foo() { std::cout << "Derived1::foo\n"; }
};

class Derived2 : public Base
{
  public:
    Derived2() {std::cout << "Derived2\n"; }
    using Base::foo;
    void foo() { std::cout << "Derived2::foo\n"; }
};

void Foo( Base &B ) { B.foo(); }

int main()
{
  Derived1 D1;
  Derived2 D2;

  std::cout << "\n";

  D1.foo();
  //D1.foo(1);
  D2.foo();
  D2.foo(2);

  std::cout << "\n";
  
  Derived1 &RD1 = D1;
  Derived2 &RD2 = D2;
  Base     &RB1 = D1;
  Base     &RB2 = D2;

  RD1.foo();
  //D1.foo(1);
  RD2.foo();
  RD2.foo(2);

  RB1.foo();
  RB1.foo(1);
  RB2.foo();
  RB2.foo(2);

  std::cout << "\n";

  Derived1 *PD1 = &D1;
  Base     *BD1 = &D1;
  Derived2 *PD2 = &D2;
  Base     *BD2 = &D2;

  std::cout << "\n";

  PD1->foo();
  BD1->foo();
  BD1->foo(1);
  PD2->foo();
  BD2->foo();
  BD2->foo(1);

  std::cout << "\n";

  Foo(D1);
  Foo(D2);
  Foo(*PD1);
  Foo(*BD1);
  Foo(*PD2);
  Foo(*BD2);

  return 1;
}
