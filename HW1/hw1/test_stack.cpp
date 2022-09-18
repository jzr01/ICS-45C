 #include "stack.h"
 #include <iostream>
using namespace std;
int main()
{
  std::string my_str;
  while (std::getline(std::cin,my_str))
  {
    Stack my_stack;
    for (int i = 0; i < my_str.length(); i++)
    {
      my_stack.push(my_str[i]);

    }

    while (! my_stack.isEmpty()) 
    {
      char top_char = my_stack.pop();
      cout << top_char;
    }
    
    cout << "\n";
  }
  return 0;
}
