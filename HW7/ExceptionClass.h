#ifndef EXCEPTIONCLASS_H
#define EXCEPTIONCLASS_H

using namespace std;

class IndexOutOfBoundsException
{
  public:
   string error;

   IndexOutOfBoundsException(string s)
  {
    error = s;
  }


};

#endif