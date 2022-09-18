#define MAXLEN 128
#include <iostream>
#include <stdlib.h>
using namespace std;

class String
{
public:
  /// both constructures should construct this String from the parameters
  explicit String(const char * s = "")
  {
    strcpy(buf,s);
  };
  
  String(const String & s)
  {
    for (int i = 0; i < MAXLEN ; i++)
    {
      buf[i] = s.buf[i];
    }
  }


  String operator = (const String & s)
  {
    for (int i = 0; i < MAXLEN ; i++)
    {
      buf[i] = s.buf[i];
    }
    return *this;
  }

  char & operator [] (int index)
  {
    if (inBounds(index))
    {
      char & a =  buf[index];
      return a;
    }else
    {
      cout << "Invalid Index" << endl;
      char & a =  buf[index];
      return a;
    }
  }

  int size()
  {
    return strlen(buf);
  }

  String reverse()
  {
    String result = String();
    reverse_cpy(result.buf,buf);
    return result;
  }

  int indexOf( const char c)
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

  int indexOf(const String pattern)
  {
    if (strlen(buf) > strlen(pattern.buf)){
    int m = -1;
    for (int i = 0; i < strlen(buf)- strlen(pattern.buf) + 1;i++)
    {
      bool match = true;
      for (int j = 0; j < strlen(pattern.buf);j++)
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
    }else if (strlen(buf) == strlen(pattern.buf))
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


  bool operator == (const String s)
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

  bool operator != (const String s)
  {
    return ! this->operator == (s);
  }

  bool operator > (const String s)
  {
    if (strcmp(buf,s.buf) > 0)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  bool operator < (const String s)
  {
    return ! this->operator >= (s);
  }

  bool operator <= (const String s)
  {
    return ! this->operator > (s);
  }

  bool operator >= (const String s)
  {
    return this->operator == (s) || this->operator > (s);
  }

  /// concatenate this and s to return result
  String operator + (const String s)
  { 
    String result = String(*this);
    return String(strcat(result.buf,s.buf));
  }

  /// concatenate s onto end of this string
  String operator += (const String s)
  {
    strcat(buf,s.buf);
    return *this;
  }

  void print (ostream & out)
  {
    out << buf;
  }

  void read (istream & in)
  {
    in >> buf;
  }

  ~String(){};

private:
  bool inBounds(int i)
  {
    return i>= 0 && i < strlen(buf);
  } //Hint: some c string primitives you should define and use

  static int strlen(const char *s)
  {
    int length = 0;

    if (s != nullptr)
    {
      while (s[length] != '\0' )
      {
        length++;
      }
    }
    return length;
  }

  static char * strcpy(char *dest, const char *scr)
  {
    char * ptr = dest;
    for (int i = 0; i < strlen(scr); i++)
    {
      dest[i] = scr[i];
    } 
    dest[strlen(scr)] = '\0';
    return ptr;
  }

  static char * strcat(char *dest, const char *src)
  {
    int i, j;
    for (i = 0; dest[i] != '\0'; i++);
    for (j = 0; src[j] != '\0'; j++) {
        dest[i + j] = src[j];
    }
    dest[i + j] = '\0';
    return dest;
  }

  static int strcmp(const char* left, const char* right)
  {
    while(*left && (*left == * right))
    {
      left++;
      right++;
    }
    return *(const unsigned char*)left - *(const unsigned char*)right;
  }

  static int strncmp(const char *left, const char *right, int n)
  {
    while ( n && *left && ( *left == *right ) )
    {
      ++left;
      ++right;
      --n;
    }
    if ( n == 0 )
    {
      return 0;
    }
    else
    {
      return ( *(unsigned char *)left - *(unsigned char *)right );
    }
  }

  static char * strchr(char *str, char c)
  {
    char *a = nullptr;
    for (int i = 0; i< strlen(str);i++)
    {
      if (str[i] == c)
      {
        a = & (str[i]);
        break;
      }
    }
    return a;
  }

  static const char * strstr(const char *haystack, const char *needle)
  {
    const char *a;
    if (strlen(haystack) >= strlen(needle))
    {
      for (int i = 0; i < strlen(haystack)- strlen(needle) + 1;i++)
      {
        bool match = true;
        for (int j = 0; j < strlen(needle) ;j++)
        {
          if (haystack[i+j] != needle[j] )
          {
            match = false;
          }
        }
        if (match)
        {
          a = & (haystack[i]);
          break;
        }
      }
    return a;
    }else
    {
      const char* a = nullptr;
      return a;
    }
  }

  static char * strstr( char *haystack, const char *needle)
  {
    char *a;
    if (strlen(haystack) >= strlen(needle))
    {
      for (int i = 0; i < strlen(haystack)- strlen(needle) + 1;i++)
      {
        bool match = true;
        for (int j = 0; j < strlen(needle) ;j++)
        {
          if (haystack[i+j] != needle[j] )
          {
            match = false;
          }
        }
        if (match)
        {
          a = & (haystack[i]);
          break;
        }
      }
    return a;
    }else
    {
      char* a = nullptr;
      return a;
    }
  }

  static void reverse_cpy(char *dest,const char * scr)
  {
    for (int i = 0; i < strlen(scr); i++)
    {
      dest[i] = scr[strlen(scr)-1-i];
    } 
    dest[strlen(scr)] = '\0';
  }
  
  char buf[MAXLEN];// array for the characters in this string 
  //Do not store the 'logical' length of this string
  // use the null '\0' terinator to mark the end

};

ostream & operator << (ostream & out, String str)
{
  str.print(out);
  return out;
};

istream & operator >> (istream & in, String & str)
{
  str.read(in);
  return in;
};