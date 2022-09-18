#include "String.cpp"
#include <iostream>
using namespace std;

void test_constructors_and_print()
{
  String s = String("Hello World");
  cout << s << endl;

}

void test_assignment()
{
  String a;
  String s("Hello World");
  a = s;
  cout << a << endl;
}

void test_relationals()
{
  String a("acd");
  String b("abcdefs");
  String c("acd");
  cout << (a == b) << endl;
  cout << (a != b) << endl;
  cout << (a == c) << endl;
  cout << (a > c) << endl;
  cout << (a <= c) << endl;
}

void test_reverse()
{
  String a("abcdef");
  cout << a.reverse() << endl;
}

void test_concatenation()
{
  String a("abc");
  String b("123");
  cout << a + b << endl;
  cout << a << endl;
  a += b;
  cout << a << endl;
}

int main()
{
  test_constructors_and_print();
  test_assignment();
  test_relationals();
  test_reverse();
  test_concatenation();
  return 0;
}