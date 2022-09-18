#include <iostream>
using namespace std;

int main()
{
  int  a =  1;
  int * b =  a;
  a = a + 1;
  cout << a <<" "<< b << endl;
  return 0;
}