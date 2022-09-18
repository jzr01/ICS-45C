#ifndef TEST_MATRIX_CPP
#define TEST_MATRIX_CPP

#include <iostream>
#include "Matrix.h"
using namespace std;

template
  < typename T >
void fillMatrix( Matrix <T> & m )
{
  int i, j;
  for ( i = 0; i < m.numRows(); i++ )
    m[i][0] = T();
  for ( j = 0; j < m.numCols(); j++ )
    m[0][j] = T();
  for ( i = 1; i < m.numRows(); i++ )
    for ( j = 1; j < m.numCols(); j++ )
    {
      m[i][j] = T(i * j);
    }
}

void test_int_matrix()
{ // here is a start, but make it better
    Matrix < int > m(10,5);
    fillMatrix( m );
    cout << m;
}

void test_double_matrix()
{ // here is a start, but make it better
	   Matrix < double > M(8,10);
    fillMatrix( M );
    cout << M;
}

void test_double_matrix_exceptions()
  throw ()
{
  try{
    Matrix <int> M1(2,2);
    M1[0][-1]  = 10.0;
  }
  catch (const IndexOutOfBoundsException & e)
  {
    cout << e.error << endl;
  }
}


int main()
{
   test_int_matrix();
   test_double_matrix();
   test_double_matrix_exceptions();
   return 0;
}

#endif