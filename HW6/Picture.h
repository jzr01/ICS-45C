#ifndef PICTURE_H
#define PICTURE_H

#include <iostream>
using namespace std;
#include "Shape.h"

class Picture
{

  struct ListNode
  {
    public:
      Shape * info;
      ListNode * next;
      ListNode(Shape *  newInfo, ListNode * newNext)
      : info( newInfo ), next( newNext )
      {
      }

      static ListNode * copy(ListNode * L)
      {
        return L == nullptr ? nullptr : new ListNode(L->info,copy(L->next));
      }

      static ListNode * append(ListNode * L1, ListNode * L2)
      {
        return L1 == nullptr ? copy(L2)
          : new ListNode(L1->info,append(L1->next,L2));
      }

      static void deleteList(ListNode * L)
      {
        if (L)
        {
          deleteList(L->next);
          delete L;
        }
      }
  };
  
  ListNode * head;

  public:
    Picture()
      : head(0)
    {
    }

    void add(Shape * sp)
    {
      ListNode * temp = head;
      ListNode * temp1 = new ListNode(sp,nullptr);
      head = ListNode::append(head,temp1);
      ListNode::deleteList(temp);
      ListNode::deleteList(temp1);
    }

    void drawAll()
    {
      for (ListNode * p = head; p != nullptr; p = p ->next)
      {
        p->info->draw();
      }
    }

    double totalArea()
    {
      double a = 0.0;
      for (ListNode * p = head; p != nullptr; p = p ->next)
      {
        a += p->info->area();
      }
      return a;
    }

    ~Picture()
    {
      ListNode::deleteList(head);
    }
    
};

#endif