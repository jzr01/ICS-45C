#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include "Array.h"
#include "ExceptionClass.h"
using namespace std;

template
  <typename Element>
class Matrix
{
private:
  int rows, cols;
  // define m as an Array of Array pointers using the 
  // template you defined above
  Array < Array < Element > * >  m;

public:
  Matrix( int newRows, int newCols )
    : rows( newRows ), cols( newCols ), m( rows )
  {
    for (int i = 0; i < rows; i++ )
      m[i] = new Array < Element >( cols );
  }

  int numRows()
  {
    return rows;
  }

  int numCols()
  {
    return cols;
  }

  Array < Element > & operator [] ( int row )
     throw  (IndexOutOfBoundsException)
  {
    
    if (row >= rows || row < 0)
    {
      throw (IndexOutOfBoundsException("Index Out of Bounds Exception"));
    }
    return * m[row];
  }

  void print( ostream & out )
  {
    for (int i = 0 ; i < rows; i++)
    {
      out << m[i] << endl;
    }
  }

  friend ostream & operator << ( ostream & out, Matrix & m )
  {
    m.print( out );
    return out;
  }
};

#endif