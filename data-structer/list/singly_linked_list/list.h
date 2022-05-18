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
		Node<T>* p = new Node<T>;
		p->value = v;
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
		return p->value;
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

	int Count(T val) const
	{
		int counter = 0;
		Node<T>* p = head;
		while (p->next != NULL)
		{
			if (val == p->value) {
				counter++;
			}
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
		Node<T>* deleteItem = p->next;
		p->next = deleteItem->next;
	}

	void Delete(int startPos, int endPos)
	{
		Node<T>* p = head;
		Node<T>* n = new Node<T>;
		for (int i = 1; i < endPos - 1; i++) {
			if (i == startPos - 1) {
				n = p;
			}
			p = p->next;
		}

		n->next = p->next;
	}

	void DeleteByVal(T val) 
	{
		Node<T>* p = head;
		for(int i = 1; i <= this->Count(); i++) {
			if(p->value == val) {
				this->Delete(i);
				i--;
			}
			p = p->next;
		}
	}

	void Print()
	{
		Node<T>* p = head;
		for (int i = 0; i < this->Count(); i++) {
			cout << this->Get(i+1) << "\t";
			p = p->next;
		}
	}

	void Println(int start, int end) 
	{
		Node<T>* p = head;
		for (int i = start; i < end; i++) {
			cout << this->Get(i) << "\t";
		}
		cout << endl;
	};

	void Println()
	{
		Node<T>* p = head;
		for (int i = 0; i < this->Count(); i++) {
			cout << this->Get(i+1) << "\t";
			p = p->next;
		}
		cout << endl;
	}

	void Insert(int pos, T v)
	{
		Node<T>* p = head;
		if (pos == 1)
		{
			Node<T>* n = new Node<T>;
			n->value = v;
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
			n->value = v;
			n->next = p->next;
			p->next = n;	
		} else {
			this->Add(v);
		}
	}

	void Swap(int pos1, int pos2) 
	{
		Node<T>* p1 = head;
		int i = 1;
		for (i = 1; i < pos1 - 1; i++) {
			p1 = p1->next;
		}
		Node<T>* p2 = p1;
		for (i = pos1 -1 ; i < pos2 - 1; i++) {
			p2 = p2->next;
		}
		cout << p1->value << endl;
		cout << p2->value << endl;

		// Node<T>* nPos1 = p1;
		Node<T>* nPos2 = p2->next;
		// Node<T>* nPos11 = nPos1->next;
		// Node<T>* nPos22 = nPos2->next;

		p1 = nPos2;
		p1->next = nPos2->next;

		cout << p1->value<< endl;
	};

	int findFirstIndex(T val) 
	{
		Node<T>* p = head;
		for(int i = 0; i < this->Count(); i++) {
			if (p->value == val) {
				return i + 1;
			} else {
				p=p->next;
			}
		}
		return -1;
	};

	int findLastIndex(T val) 
	{
		Node<T>* p = head;
		int index = -1;
		for(int i = 1; i < this->Count(); i++) {
			if (p->value == val) {
				index = i + 1;
			}
			p = p->next;
		}

		return index;
	};

	void Replace(int pos, T val) 
	{
		Node<T>* p = head;
		int index = -1;
		for(int i = 1; i < pos; i++) {
			p = p->next;
		}
		p->value = val;
	};

	void Replace(int start, int end, T val) 
	{
		Node<T>* p = head;
		for (int i = 0; i < start-1; i++) {
			p = p->next;
		}
		for (int i = start - 1; i < end; i++) {
			p->value = val;
			p = p->next;
		}
	};


	bool Some(int val) 
	{
		bool isExisting = false;
		Node<T>* p = head;
		for(int i = 1; i < this->Count(); i++) {
			if (p->value == val) {
				isExisting = true;
				break;
			}
			p = p->next;
		}

		return isExisting;
	};

	T *Find(T minimum, T maximum) 
	{
   	static T result[5000];
   	int index = 0;
	  for (int i = 1; i < this->Count(); i++) {
	  	T value = this->Get(i);
	  	if (value < maximum && value > minimum) {
	  		result[index++] = value;
	  	}
	  }
   
   	return result;
	};

	T *Find(int start, int end, T value) 
	{
   	static T result[5000];

   	int index = 0;
	  for (int i = start - 1; i < end; i++) {
	  	T val = this->Get(i);
	  	if (value == val) {
		  	result[index] = i;
		  	index++;
	  	}
	  }
   
   	return result;
	};

	T *Slice(int startPos) 
	{
		static T result[5000]; 
		int index = 0;
		for (int i = startPos; i <= this->Count(); i++) {
			result[index] = this->Get(i);
			index++;
		}
		return result;
	};

	T *Slice(int startPos, int endPos) 
	{
		static T result[5000]; 
		int index = 0;
		for (int i = startPos; i < endPos; i++) {
			result[index] = this->Get(i);
			index++;
		}
		return result;
	};

	void Concat(T values[], int length) 
	{
		for(int i = 0; i < length; i++)
		{
			Node<T>* n = new Node<T>;
			n->value = values[i];
			n->next = NULL;
			if (head == NULL) {
				head = n;
			} else {
				Node<T>* p = head;
				for (int i = 1; i < this->Count(); i++)
				{
					p = p->next;
				}
				p->next = n;
			}
		}
	}
};

#endif