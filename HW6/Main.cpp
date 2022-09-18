#include <iostream>
using namespace std;
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Picture.h"

int main()
{
  Picture p;
  p.add(new Triangle(0,0,"T1",17,9));
  p.add(new Triangle(0,0,"T2",21,7));
  p.add(new Triangle(0,0,"T3",16,8));
  p.add(new Circle(0,0,"C1",5));
  p.add(new Circle(0,0,"C1",10));
  p.add(new Square(0,0,"S1",5));
  p.add(new Square(0,0,"S1",10));
  p.add(new Rectangle(0,0,"R1",8,4));
  p.add(new Rectangle(0,0,"R1",4,8));
  p.drawAll();
  cout << p.totalArea() << endl;
  return 0;
}