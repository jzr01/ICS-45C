#include <iostream>
using namespace std;

template 
    <typename T> 
struct ListNode
{
    T info;
    ListNode* next; 
    ListNode(T newinfo, ListNode* next1)
    :info(newinfo),next(next1){}
};

template 
    <typename M>
class SetList
{
    public:
    ListNode<M> * head;
    
    struct iterator
    {
        typedef forward_iterator_tag iterator_category;
        typedef iterator self_type;
        typedef M value_type;
        typedef M& reference;
        typedef M* pointer;
        typedef ptrdiff_t difference_type;
    private:
        ListNode<M>* ibuf;
    public:
        iterator(ListNode<M>* ptr) : ibuf(ptr) {}
        self_type operator++() { ibuf = ibuf->next; return *this; }
        reference operator*() { return ibuf->info; }
        pointer operator->() { return ibuf; }
        bool operator==(const self_type& rhs) const { return ibuf == rhs.ibuf; }
        bool operator!=(const self_type& rhs) const { return ibuf != rhs.ibuf; }
    };

    struct const_iterator
    {
        typedef forward_iterator_tag iterator_category;
        typedef const_iterator self_type;
        typedef M value_type;
        typedef M& reference;
        typedef M* pointer;
        typedef ptrdiff_t difference_type;
    private:
        ListNode<M>* buf;
    public:
        const_iterator(ListNode<M>* ptr) : buf(ptr) {}
        self_type operator++() { buf = buf->next; return *this; }
        const reference operator*() { return buf->info; }
        const pointer operator->() { return buf; }
        bool operator==(const self_type& rhs) const { return buf == rhs.buf; }
        bool operator!=(const self_type& rhs) const { return buf != rhs.buf; }
    };

    SetList(){head = new ListNode<M>;}
    SetList(const SetList<M> & s)
    {
        head = s.head;
    }

    iterator begin()
    {
        return iterator(head);
    }

    iterator end()
    {
        ListNode<M> * temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        return iterator(temp);
    }

    const_iterator begin() const
    {
        return const_iterator(head);
    }

    const_iterator end() const
    {
        ListNode<M> * temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        return const_iterator(temp);
    }

    SetList<M> insert(M val)
    {
        ListNode<M> * temp = new ListNode<M>(val,nullptr);
        if (find(val) != end())
        {
            temp->next = head;
            head = temp;
        }
        return *this;
    }

    iterator find(M val)
    {
        ListNode<M> * temp = head;
        while (temp->info != val && temp->next != nullptr)
        {
            temp = temp->next;
        }

        return iterator(temp);

    }

    const_iterator find(M val) const
    {
        ListNode<M> * temp = head;
        while (temp->info != val && temp->next != nullptr)
        {
            temp = temp->next;
        }

        return const_iterator(temp);
    }


    ~SetList()
    {
        delete[] head;
    }
};