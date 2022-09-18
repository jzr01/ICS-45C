#ifndef A_CPP
#define A_CPP

#include <iostream>
#include <cassert>
#include <iomanip>
#include "Matrix.h"
using namespace std;


int main()
{
  // Array<int> a(3);
  // cout << a.length() << endl;
  // a[0] = 1;
  // a[1] = 2;
  // a[2] = 3;
  // cout << a << endl;

  Matrix<int> b(3,3);
  cout << b.numRows() << endl;
  cout << b.numCols() << endl;
  b[1][1] = 1;
  cout << b << endl;
  
}

#endif