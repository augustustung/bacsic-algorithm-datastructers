#include <iostream>
using namespace std;
#include "stack.h"

int main() 
{
	Stack<int> list;
	int i = 1;
	while(1)
	{
		list.Push(i);
		i++;
		cout << list.Pop() << endl;
	}
	return 0;
}