#include <iostream>
using namespace std;
#include "tree.h"
int main() 
{
  Tree<int> t;
  t.Add(10);
  t.Add(20);
  t.Add(30);
  t.Add(40);
  t.Add(50);
  t.Add(26);
  cout<<"Tu trai sang phai: \n";
  t.GetLeftToRight();

//       30
//     /    \
//   20      40
// /    \      \
// 10   26     50

  t.Add(8);
  t.Add(3);
  t.GetLeftToRight();
//         30
//       /    \
//     20      40
//   /    \      \
//   8   25      50
// /  \
// 3  10
}