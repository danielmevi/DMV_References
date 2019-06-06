/*
 * This code is about to reproduce the dynamic cast failing from the hybrid
 * queue of the idi xtor
 *
 */

#include <deque>
#include <iostream>

struct Base
{
  int  A;
  int  B;
  char C;
  virtual ~Base();
};

struct Base2 : public Base
{
  int D;
  int E;
  //virtual ~Base2() {}
};

struct Derived : public Base2
{
  int F;
  int G;
  //virtual ~Derived() {}
};

Base::~Base() {}

void push(std::deque<Base *> &queue, Base *obj) { queue.push_back(obj); }

Base *pop(std::deque<Base *> &queue) { return queue.front(); }

int main(int, char *[])
{
  std::deque<Base *> myqueue;
  Derived            D1;

  D1.A = 1;
  D1.B = 2;
  D1.C = 3;

  push(myqueue, &D1);

  Base    *B2 = pop(myqueue);
  Derived *D2 = dynamic_cast<Derived*>(B2);

  std::cout << D2 << std::endl;

  myqueue.pop_back();

  return 0;
}

