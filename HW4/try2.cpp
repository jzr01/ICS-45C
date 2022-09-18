#include "String.cpp"
#include <iostream>
using namespace std;

int main()
{
  String A("YABA");
  String B("DABA");
  String C("DOO");
  C = A+B+C;
  cout << C << endl;
  return 0;
}