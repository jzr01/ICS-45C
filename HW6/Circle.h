#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
using namespace std;
#include "Shape.h"

class Circle : public Shape
{
  private:
    const double PI = 3.14159;
  protected:
    int radius;
  public:
    Circle(int x, int y, string n, int r)
      :Shape(x,y,n),radius(r)
    {
    }

    virtual double area()
    {
      return PI*radius*radius;
    }
    
    virtual void draw()
    {
      for (int y = -radius; y <= radius; y++)
      {
        for (int x = -radius; x <=radius; x++)
        {
          std::cout << ((x*x+y*y == radius*radius) ? "* " : "  ");
          
        }
        std :: cout << std :: endl;
      }
    }
};

#endif