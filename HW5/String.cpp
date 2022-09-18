#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#include "String.h"

String::String( const char * s) //problem
{
  head = ListNode::stringToList(s);
}
    
String::String( const String & s )
{
  head = ListNode::copy(s.head);
}
    
String String::operator = ( const String & s )
{
  ListNode * temp = head;
  head = ListNode::copy(s.head);
  ListNode::deleteList(temp);
  return *this;
}

char & String::operator [] ( const int index )
{
  int i = index;
  if (inBounds(i))
  {
    String::ListNode * a = head;
    while (i > 0)
    {
      a = a -> next;
      i--;
    } 
    return a -> info;
  }
  return head->info;
};
    
int String::size() const
{
  return ListNode::length(head);
}
    
int String::indexOf( char c ) const
{
  String::ListNode * a = ListNode::find(c,head);
  if (a == nullptr)
  {
    return -1;
  }
  else 
  {
    ListNode * b = head;
    int i = 0;
    while (b->info != a->info )
    {
      b = b-> next;
      i++;
    }
    return i;
  }
}

int String::indexOf(const String & pattern) const
{
  int c = 0;
  int len = ListNode::length(pattern.head);
  ListNode * r = pattern.head;
  ListNode * l = head;
  for (int i = 0; i < ListNode::length(head)-len+1; i++)
  {
    if (l->info == r->info)
    {
      ListNode * temp = l;
      while (temp != nullptr && r != nullptr && temp->info == r->info)
      {
        temp = temp -> next;
        r = r->next;
        c++;
      }
    }
    if (c==len)
    {
      return i;
    }
    l = l ->next;
    r = pattern.head;
    c = 0;
  }
  return 0;
}

bool String::operator == ( const String s ) const
{
  return ListNode::compare(head,s.head) == 0;
}

bool String::operator != ( const String s ) const
{
  return ListNode::compare(head,s.head) != 0;
}

bool String::operator < ( const String s ) const
{
  return ListNode::compare(head,s.head) < 0;
}

bool String::operator > ( const String s ) const
{
  return ListNode::compare(head,s.head) > 0;
}

bool String::operator <= ( const String s ) const
{
  return ListNode::compare(head,s.head) <= 0;
}

bool String::operator >= ( const String s ) const
{
  return ListNode::compare(head,s.head) >= 0;
}

String String::operator + ( const String s )
{
  String a;
  a.head = ListNode::append(head,s.head);
  return a;
}
    /// concatenates s onto end of this
String String::operator += ( const String s ) 
{
  ListNode * temp = head;
  head = ListNode::append(head,s.head);
  ListNode::deleteList(temp);
  return *this;
}

String String::reverse() const
{
  String a("");
  ListNode * b = ListNode::reverse(head);
  a.head = ListNode::copy(b);
  ListNode::deleteList(b);
  return a;
}

void String::print( ostream & out ) const
{
  for (ListNode * p = head; p != nullptr ; p = p->next)
  {
    out << p->info;
  }
}

void String::read( istream & in )
{
  char a[256];
  in.getline(a,256);
  ListNode::deleteList(head);
  head = ListNode::stringToList(a);
}

String::~String()
{
  ListNode::deleteList(head);
}

String::ListNode * String::ListNode::stringToList(const char *s) 
{

  if (s[0] == '\0')
  {
    return nullptr;
  }else
  {
    int i = 0;
    ListNode * h = new ListNode(s[0],nullptr);
    ListNode * a = h;
    while (s[i+1] != '\0')
    {
      a -> next = new ListNode(s[i+1],nullptr);
      a = a->next;
      i++;
    }
    return h;
  }
}

String::ListNode * String::ListNode::copy(ListNode * L)
{
  return L == nullptr ? nullptr : new ListNode(L->info,copy(L->next));
}

String::ListNode * String::ListNode::reverse(ListNode * L)
{
  ListNode * result = nullptr;
  for (ListNode * p = L; p != nullptr; p = p -> next)
    result = new ListNode(p->info,result);
  return result;
}

String::ListNode * String::ListNode::append(ListNode * L1, ListNode * L2)
{
  return L1 == nullptr ? copy(L2)
    : new ListNode(L1->info,append(L1->next,L2));
}

String::ListNode * String::ListNode::find(char c, ListNode * L)
{
  while (L != nullptr)
  {
    if (L->info == c)
    {
      return L;
    }
    L = L->next;
  }
  return L;
}

int String::ListNode::compare(ListNode * L1, ListNode * L2)
{
  int i = 0;
  while (L1 != nullptr && L2 != nullptr)
  {
    if (L1 != L2)
    {
      return *(const unsigned char*)L1 - *(const unsigned char*)L2;
    }
    L1 = L1 -> next;
    L2 = L2 -> next;
  }
  if (L1 == nullptr && L2 != nullptr)
  {
    i = - *(const unsigned char*)L2;
  }else if (L1 != nullptr && L2 == nullptr)
  {
    i = *(const unsigned char*)L1;
  }else
  {
    i = 0;
  }
  return i;
}

void String::ListNode::deleteList(ListNode * L)
{
  if (L)
  {
    deleteList(L->next);
    delete L;
  }
}

int String::ListNode::length(ListNode * L)
{
  return L == nullptr ? 0 : 1 + length(L->next);
}

ostream & operator << (ostream & out, String str)
{
  str.print(out);
  return out;
}

istream & operator >> (istream & in, String str)
{
  str.read(in);
  return in;
}