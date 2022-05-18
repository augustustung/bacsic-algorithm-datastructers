#ifndef node_h
#define node_h

template <class T>

struct Node {
	Node<T>* prev;
	T data;
	Node<T>* next;
};

#endif