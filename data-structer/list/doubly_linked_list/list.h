#ifndef list_h
#define list_h
#include<iostream>
using namespace std;
#include "node.h"

template <class T>

class List
{
private:
	Node<T>* head;
public:
	List()
	{
		head = NULL;
	};

	void Add(T v)
	{
		Node<T>* n = new Node<T>;
		n->data = v;
		n->next = NULL;

		if (head == NULL)
		{
			n->prev = NULL;
			head = n;
		}
		else
		{
			Node<T>* p = head;
			while (p->next != NULL)
			{
				p = p->next;
			}

			p->next = n;
			n->prev = p;
		}
	};

	void Replace(int pos, T val) 
	{
		Node<T>* p = head;
		for (int i = 0; i < pos-1; i++)
		{
			p = p->next;
		}
		p->data = val;
	};

	void Println() const
	{
		Node<T>* p = head;
		while(p != NULL)
		{
			cout << p->data << "\t";
			p = p->next;
		}

		cout << endl;
	};

	int Count() const
	{
		int counter = 0;
		Node<T>* p = head;
		while (p != NULL)
		{
			counter++;
			p = p->next;
		}
		return counter;
	};

	void Delete(int pos)
	{
		Node<T>* p = head;
		for (int i = 1; i < pos - 1; i++) 
		{
			p = p->next;
		}

		Node<T>* nPos = p->next;
		Node<T>* n1Pos = nPos->next;
		p->next = n1Pos;
		n1Pos->prev = p;
	}

	void DeleteByVal(T v)
	{
		Node<T>* p = head;
		int index = 1;
		while(p != NULL) 
		{
			if (p->data == v) 
			{
				this->Delete(index);
				index--;
			}
			index++;
			p = p->next;
		}
	};

	void Insert(int pos, T v)
	{
		Node<T>* n = new Node<T>;
		n->data = v;
			
		Node<T>* p = head;
		if (pos == 1)
		{
			n->prev = NULL;
			n->next = head;
			head = n;
		} 
		else if (pos == this->Count())
		{
			this->Add(v);
		}
		else 
		{
			for (int i = 1; i < pos - 1; i++)
			{
				p = p->next;
			}
			n->prev = p;
			n->next = p->next;
			p->next = n;
		}
	};
};

#endif 