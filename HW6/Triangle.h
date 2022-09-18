#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
using namespace std;
#include "Shape.h"

class Triangle : public Shape
{
  protected:
    int base;
    int height;
  public:
    Triangle(int x, int y, string n, int b, int h)
      :Shape(x,y,n),base(b),height(h)
      {
      }
    
    virtual double area()
    {
      return base*height/2.0;
    }

    virtual void draw()
    {
      for (int y =1 ; y <= height; y++)
      {
        for (int x = 1; x<= base; x++)
        {
          if (y ==1 ) std::cout <<((x == (base + 1)/2) ? "*" : " " );
          else if (y == height) std :: cout << "*";
          else std::cout << ((x == (base - (height - y))|| x == height - y +1) ? "*" : " ");
        }
        std :: cout << std:: endl;
      }
    }
};

#endif