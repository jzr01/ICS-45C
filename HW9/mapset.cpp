#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include "SetList.h"
#include <map>
#include <algorithm>
using namespace std;

string to_lower(string s)
  {
    transform(s.begin(), s.end(), s.begin(), [](unsigned char c){return std::tolower(c);});
    return s;
  }


void add_key(string s1, map<string,int> & m, SetList<string> s)
{
    if (s.find(s1) == s.end())
    {
      string s2 = to_lower(s1);
      if (m.find(s2) == m.end())
      {
        m[s2] = 1;
      }
      else
      {
        m[s2]++;
      }
    }
}

void write(pair<string,int> E, ofstream & out) 
{
  out << E.first << "," << E.second << endl;
}



int main()
{
  ifstream in_stopword("stopwords.txt");
  SetList<string> stop_set();
  for_each(istream_iterator<string>(in_stopword),istream_iterator<string>(),[&](string s){stop_set.insert(s);});
  ifstream in1("sample_doc.txt");

  vector<string> words;
  copy(istream_iterator<string>(in1),istream_iterator<string>(),back_inserter(words));
  sort(begin(words),end(words));

  map<string,int> freq;
  for_each(begin(words),end(words),[&](string s){add_key(s,freq,stop_set);});

  ofstream out("frequency.txt");
  if (out.is_open())
  {
    for_each(begin(freq),end(freq),[&](pair<string,int> E){write(E,out);});
    out.close();
  }

  return 0;
}