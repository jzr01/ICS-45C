#include <iostream>
using namespace std;
int main()
{
  int f = 2;
  int j = 3;
  int k = 4;
  int m = 6;
  bool x = f*2 <= 2*4 || j != 0 && ! k == m;
  bool y = ((f*2) <= (2*4)) || ((j != 0) && ((! (k == m))));
  cout << x;
  cout << y;

  bool a = true;
  bool b = true;
  bool c = false;
  bool d = false; 
  int e = 5;
  bool z = a || b && c || d && e +2 <= 0;
  bool r = (a||(b&&c)) || (d && ((e+2) <= 0));
  cout << z<<r;

  return 0;
}