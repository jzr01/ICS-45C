#include "String.cpp"
#include <iostream>
using namespace std;

int main()
{
  String a;
  while (cin>>a)
  {
    if (a == a.reverse())
    {
      cout << "yes" << endl;
    }else
    {
      cout <<"no" << endl;
    }
  }
  return 0;
}