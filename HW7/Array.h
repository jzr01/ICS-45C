#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <cassert>
#include <iomanip>
#include "ExceptionClass.h"
using namespace std;

template
  < typename Type>
class Array
{
private:
  int len;
  Type * buf;
public:
  Array( int newLen )
    : len( newLen ), buf( new Type [newLen] )
  {
  }

  Array( const Array & l )
    : len( l.len ), buf( new Type[l.len] )
  {
    for ( int i = 0; i < l.len; i++ )
      buf[i] = l.buf[i]; // note = is incorrect if buf elements are pointers
  }

  int length()
  {
    return len;
  }

  Type & operator [] ( int i )
  throw (IndexOutOfBoundsException)
  {

    if (0 <= i && i < len )
    {
      return buf[i];
    }else
    {
      throw (IndexOutOfBoundsException("Index Out of Bounds Exception"));
    }
  }

  // ~Array()
  // {
  //   delete buf;
  // }

  void print( ostream & out )
  {
    for (int i = 0; i < len; ++i)
      out << setw(8) << setprecision(2) << fixed << right << buf[i]; // #include <iomanip>
  }

  friend ostream & operator << ( ostream & out, Array & a )
  {
    a.print( out );
    return out;
  }

  friend ostream & operator << ( ostream & out, Array * ap )
  {
    ap->print( out );
    return out;
  }
  // note the overloading of operators << on a pointer as well
};

#endif