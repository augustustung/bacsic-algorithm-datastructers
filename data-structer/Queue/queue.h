#ifndef queue_h
#define queue_h

#include <iostream>
using namespace std;
#include "node.h"

template <class T>

class Queue
{
private:
	Node<T>* top;
public:
	Queue()
  {
    top = NULL;
  };

	~Queue()
	{
  	Node<T> *q = top;
    while(q!= 0) 
		{
			Node<T> *next = q->next;
			delete q;
			q = next;
    }
    top = NULL;
	};

	void EnQueue(T value)
  {
    Node<T>* p = new Node<T>;
    p->next = NULL;
    p->data = value;
    if (top == NULL)
    {
      top = p;
    }
    else
    {
      Node<T>* n = top;
      while(n != NULL)
      {
        n = n->next;
      }
      n->next = p;
    }
  };

  T DeQueue()
  {
    T value = top->data;
    Node<T>* p = top;
    top = top->next;
    delete p;
    return value;
  };

  T getFirst() const
  {
    return top->data;
  };

  T getTail() const
  {
    Node<T>* p = top;
    while(p != NULL)
    {
      p = p->next;
    }
    return p->data;
  };

	bool isEmpty() const
  {
    return top == 0;
  };
};

#endif