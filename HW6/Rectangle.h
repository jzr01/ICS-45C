#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
using namespace std;
#include "Shape.h"

class Rectangle : public Shape
{
  private:
    double length;
    double width;
  public:
    Rectangle(int x, int y, string n, double l, double w)
      :Shape::Shape(x,y,n),length(l),width(w)
    {
    }

    virtual double area()
    {
      return width*length;
    }

    virtual void draw()
    {
      for (int y = 1; y <= length; y++)
      {
        for (int x = 1; x<= width; x++)
        {
          if (y == 1 || y == length) std::cout << "* ";
          else if (x==1) std::cout << "* ";
          else if (x == width) std::cout << "*";
          else std::cout << "  ";
        }
        std :: cout << std::endl;
      }
    }
};

#endif