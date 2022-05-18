#ifndef stack_h
#define stack_h

#include <iostream>
using namespace std;
#include "node.h"

template <class T>

class Stack
{
private:
	Node<T>* top;
public:
	Stack()
  {
    top = NULL;
  };

	~Stack()
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

	void Push(T value)
  {
    Node<T>* p = new Node<T>;
    p->data = value;
    p->next = top;
    top = p;
  };

	T Pop()
  {    
    T value = top->data;
    Node<T>* p = top;
    top = top->next;
    delete p;
    return value;
  };

	T getTop() const
  {
    return top->data;
  };

	bool isEmpty() const
  {
    return top == 0;
  };
};

#endif