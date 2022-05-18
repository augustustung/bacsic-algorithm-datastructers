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

	List(int quantity, T val)
	{
		head = NULL;
		for (int i = 0; i < quantity; i++)
		{
			this->Add(val);
		}
	};

	void Add(T v)
	{
		Node<T>* p = new Node<T>;
		p->data = v;
		p->next = NULL;
		if (head == NULL) {
			head = p;
		} else {
			Node<T>* n = head;
			while (n->next != NULL) {
				n = n->next;
			}
			n->next = p;
		}
	};

	T Get(int pos) const 
	{
		Node<T>* p = head;
		for (int i = 1; i < pos; i++)
		{
			p = p->next;
		}
		return p->data;
	}

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

	void Replace(int pos, T val) 
	{
		Node<T>* p = head;
		int index = -1;
		for(int i = 1; i < pos; i++) {
			p = p->next;
		}
		p->data = val;
	};

	void Insert(int pos, T v)
	{
		Node<T>* p = head;
		if (pos == 1)
		{
			Node<T>* n = new Node<T>;
			n->data = v;
			n->next = p;
			head = n;
		} 
		else if (pos <= this->Count())
		{
			for (int i = 1; i < pos - 1; i++)
			{
				p = p->next;
			}
			Node<T>* n = new Node<T>;
			n->data = v;
			n->next = p->next;
			p->next = n;	
		} else {
			this->Add(v);
		}
	}

	void Delete(int pos)
	{
		Node<T>* p = head;
		for (int i = 1; i < pos - 1; i++) 
		{
			p = p->next;
		}
		Node<T>* deleteItem = p->next;
		p->next = deleteItem->next;
	}

	void Println()
	{
		Node<T>* p = head;
		while (p != NULL)
		{
			cout << p->data << "\t";
			p = p->next;

		}
		cout << endl;
	}

	int FindFirstIndex(T val) 
	{
		Node<T>* p = head;
		for(int i = 0; i < this->Count(); i++) {
			if (p->data == val) {
				return i + 1;
			} else {
				p=p->next;
			}
		}
		return -1;
	};

	int FindLastIndex(T val) 
	{
		Node<T>* p = head;
		int index = -1;
		for(int i = 1; i < this->Count(); i++) {
			if (p->data == val) {
				index = i + 1;
			}
			p = p->next;
		}

		return index;
	};

	bool Some(int val) 
	{
		bool isExisting = false;
		Node<T>* p = head;
		for(int i = 1; i < this->Count(); i++) {
			if (p->data == val) {
				isExisting = true;
				break;
			}
			p = p->next;
		}

		return isExisting;
	};
};

#endif