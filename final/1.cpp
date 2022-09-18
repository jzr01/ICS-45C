#include <iostream>
using namespace std;

class Q{
  public:
    virtual void b();
    virtual void c() = 0;
    void d();
};

class R : public Q{
  public:
   virtual void c();
   void d();
   virtual void f();
};

class S : private R{
  public:
   S(int i);
   using R::c;
   virtual void g();
};

int main()
{
  auto a = 1;
  a = 1.1;
  string b = a;
  cout << a << b;
}



  