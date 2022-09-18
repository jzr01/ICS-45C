#include <iostream>
using namespace std;
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Square.h"

int main()
{
  Circle c(0,0,"a",10.0);
  c.draw();
  cout << c.area() << endl;
  Triangle a(0,0,"b",10,10);
  a.draw();
  cout << a.area() << endl;
  Rectangle d(0,0,"b",10,5);
  d.draw();
  cout << d.area() << endl;
  Square e(0,0,"c",10);
  e.draw();
  cout << e.area() << endl;


}