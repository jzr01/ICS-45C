#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
using namespace std;
#include "Rectangle.h"

class Square : public Rectangle 
{
  public:
    Square(int x, int y, string n, double s)
      : Rectangle(x,y,n,s,s)
    {
    }

};

#endif