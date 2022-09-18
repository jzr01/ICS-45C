#define MAXLEN 128
#include <iostream>
#include <stdlib.h>
using namespace std;

class String
{
public:
  /// both constructures should construct this String from the parameters
  String(const String & s)
  {
    for (int i = 0; i < MAXLEN ; i++)
    {
      buf[i] = s.buf[i];
    }
  }

  String reverse()
  {
    String result = String();
    revcpy(result.buf,buf);
    return result;
  }

private:
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

  static char revcpy(char dest, char scr)
  {
    const char *scr1 = & scr;
    for (int i = 0; i < strlen(scr1); i++)
    {
      dest[i] = scr[strlen(scr1)-1-i];
    } 
    dest[strlen(scr1)] = '\0';
    return dest;
  }
  
  char buf[MAXLEN];
}