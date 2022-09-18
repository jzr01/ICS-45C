#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#include "String.h"

int String::allocations = 0;

String::String(const char *s)
{
  this->buf = strdup(s);
}

String::String(const String & s )
{
  this->buf = strdup(s.buf);
}

String String::operator = ( const String & s )
{
  delete_char_array(buf);
  buf = strdup(s.buf);
  return *this;
}

char & String::operator [] ( int index )
{
  return buf[index];
}

int String::size()
{
  return strlen(buf);
}

String String::reverse()  // does not modify this String
{
  int len = strlen(buf) - 1;
  int i;
  char * temp = new_char_array(len+2);
  for (i = 0; i <= len; i++)
  {
    temp[i] = buf[len-i];
  }
  temp[strlen(buf)] = '\0';
  String a(temp);
  delete_char_array(temp);
  return a;
};

int String::indexOf( const char c )
{
  int j = 0;
  bool match = false;
  for (int i = 0; inBounds(i);i++)
  {
    if (buf[i] == c)
    {
      match = true;
      j = i;
      break;
    }
  }
  if (match)
  {
    return j;
  }else
  {
    return -1;
  } 
}

int String::indexOf( const String pattern )
{
  int l1 = strlen(buf);
  int l2 = strlen(pattern.buf);
  if (l1> l2){
    int m = -1;
    for (int i = 0; i < l1- l2 + 1;i++)
    {
      bool match = true;
      for (int j = 0; j < l2;j++)
      {
        if (buf[i+j] != pattern.buf[j] )
        {
          match = false;
        }
      }
      if (match)
      {
        m = i;
        break;
      }
    }
    return m;
    }else if (l1 == l2)
    {
      if (this->operator == (pattern))
      {
        return 0;
      }
      else
      {
        return -1;
      }
    }else
    {
      return -1;
    }
}

bool String::operator == ( const String s )
{
  if (strcmp(buf,s.buf) == 0)
    {
      return true;
    }
    else
    {
      return false;
    }
}

bool String::operator != ( const String s )
{
  return ! this->operator==(s);
};

bool String::operator > ( const String s )
{
  return strcmp(buf,s.buf) > 0;
};

bool String::operator < ( const String s )
{
  return strcmp(buf,s.buf) < 0;
};

bool String::operator <= ( const String s )
{
  return ! this->operator>(s);
};

bool String::operator >= ( const String s ) 
{
  return ! this->operator<(s);
};

String String::operator + ( const String s ) 
{
  // char* temp = strcat(buf,s.buf);
  // String s1 = String(temp);
  // delete_char_array(temp);
  // return s1;
  return str2dup(buf,s.buf);
};

String String::operator += ( const String s )
{
  char* temp = buf;
  buf = strcat(buf,s.buf);
  delete_char_array(temp);
  return *this;
};

void String::print( ostream & out )
{
  out << buf;
};

void String::read( istream & in )
{
  in >> buf;
};

bool String::inBounds( int i )
  {
    return i >= 0 && i < strlen(buf);
  };

int String::strlen(const char *src)
{
  int length = 0;

  while (src[length] != '\0' )
  {
    length++;
  }
  return length;
};

char * String::strdup(const char *src)
{
    int len = strlen(src);
    char * str = new_char_array(len + 1);
    for (int i = 0; i <= len;i++)
    {
      str[i] = src[i];
    }
    return str;
}

int String::strcmp(const char* left, const char* right)
  {
    while(*left && (*left == * right))
    {
      left++;
      right++;
    }
    return *(const unsigned char*)left - *(const unsigned char*)right;
  }

char * String::strcat(char *dest, const char *src)
  {
    int l1 = strlen(dest);
    int l2 = strlen(src);
    char * str1 = new_char_array(l1+l2+1);
    for (int i = 0; i < l1 ;i++)
    {
      str1[i] = dest[i];
    }
    for (int j = 0; j < l2 ; j++)
    {
      str1[j+l1] = src[j];  
    }
    str1[l1+l2] = '\0';
    return str1;
  }

char * String::new_char_array(int n_bytes)
{
  ++allocations;
  return new char[n_bytes];
}

String String::str2dup(char *dest, char *src)
  {
    int l1 = strlen(dest);
    int l2 = strlen(src);
    char * str1 = new_char_array(l1+l2+1);
    for (int i = 0; i < l1 ;i++)
    {
      str1[i] = dest[i];
    }
    for (int j = 0; j < l2 ; j++)
    {
      str1[j+l1] = src[j];  
    }
    str1[l1+l2] = '\0';
    String a(str1);
    return a;
  }


void String::delete_char_array(char * p)
{
  
  --allocations;
  if (allocations < 0)
  {
    cout << "more delete[] than new[]" << endl;
  }
  delete [] p;

}


String::~String()
{
  delete_char_array(buf); 
}

ostream & operator << ( ostream & out, String str )
{
  str.print(out);
  return out;
}

istream & operator >> ( istream & in, String & str )
{
  str.read(in);
  return in;
}