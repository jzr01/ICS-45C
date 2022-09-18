#include <iostream>
#include <utility>
using namespace std;

template <typename T, typename M>
class MapArray
{
  public:

  pair<T,M>* buf[10000];
  int size;

  struct iterator
    {
      typedef iterator self_type;
      typedef pair<T,M> value_type;
      typedef pair<T,M>& reference;
      typedef pair<T,M>* pointer;
      typedef ptrdiff_t difference_type;
    private:
        pointer ibuf;
    public:
        iterator(pair<T,M>* ptr) : ibuf(ptr) {}
        self_type operator++() { ++ibuf; return *this; }  
        reference operator*() { return *ibuf; }
        pointer operator->() { return ibuf; }
        bool operator==(const self_type& rhs) const { return ibuf == rhs.ibuf; }
        bool operator!=(const self_type& rhs) const { return ibuf != rhs.ibuf; }
    };
    MapArray():size(0){}
    iterator begin(){return iterator(buf[0]);}
    iterator end(){return iterator(buf[size]);}
    MapArray<T,M> insert(pair<T,M> p)
    {
      buf[size++] = new pair<T,M>(p.first,p.second);
      return *this;
    }

    M& operator[](T key)
    {
      iterator temp = find(key);
      if (temp == end())
      {
        buf[size++] = new pair<T,M>(key,M());
      }
      return temp->second;
    }

    iterator find(T key)
    {
      for (int i = 0; i< size; i++)
      {
        if (buf[i]->first == key)
        {
          return iterator(buf[i]);
        }
      }
      return iterator(end());
    }

  void print( ostream & out )
  {
    for (int i = 0 ; i < size; i++)
    {
      out << buf[i]->first << "," << buf[i]->second << "\n";
    }
  };

  ~MapArray()
  {}

};


ostream & operator << ( ostream & out, MapArray<string,int> str )
{
  str.print(out);
  return out;
}