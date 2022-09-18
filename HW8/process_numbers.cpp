#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

void split(int i,ofstream & odd, ofstream & even)
{
  if (i % 2 == 0)
  {
    even << i << endl;
  }else
  {
    odd << i << " ";
  }
}

int main()
{
  ifstream in("rand_numbers.txt");
  vector<int> v;
  copy(istream_iterator<int>(in),istream_iterator<int>(),back_inserter(v));
  sort(begin(v),end(v));

  ofstream odd("odd.txt");
  ofstream even("even.txt");

  for_each(begin(v),end(v),[&](int i){split(i,odd,even);});

  odd << endl;

  return 0;
}