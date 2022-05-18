#include <iostream>
using namespace std;
#include "queue.h"

int main() {
  Queue<int> list;
  int i = 1;
  while(1) {
  	list.EnQueue(i++);
  	cout << list.DeQueue() << endl;
  }
  return 0;
}