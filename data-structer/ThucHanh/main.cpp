#include <iostream>
#include "list.h"
using namespace std;

List<int> ds;

int main()
{
	// 0 1 2 3 4
	for(int i = 0; i < 5; i++) {
		ds.Add(i);
	}

	// ds.Print();

	// 0 1 4 2 3 4
	ds.Insert(3, 4);
	
	// 4 1 0 2 3 4
	ds.Swap(1, 3);

	// 4 1 4 2 3 4
	ds.Replace(3, 4);

	// 5 5 4 2 3 4
	ds.Replace(1, 3, 5); // [start, end) = val

	// // return -1
	// cout << ds.findFirstIndex(5) << endl;
	// // return 1
	// cout << ds.findFirstIndex(4) << endl;
	// // return 6
	// cout << ds.findLastIndex(4) << endl;
	// // return 3
	// cout << ds.Count(4) << endl;
	// // return true 1
	// cout << ds.Some(4) << endl;
	// // return false 0
	// cout << ds.Some(8) << endl;
	
	int *newDs;
	// // 2 3
	// newDs = ds.Find(2, 3); // min max
	// for(int i = 0; i < ds.Count(); i++) {
	// 	int val = *(newDs + i);
	// 	if (val) {
	// 		cout << val  << endl;
	// 	} 
	// }
	// ds.Print();

	// cout << endl;
	// newDs = ds.FindExec(2, 4); // find from to [start, end)
	// for(int i = 0; i < 2; i++) {
	// 	int val = *(newDs + i);
	// 	if (val) {
	// 		cout << val  << "\t ";
	// 	} 
	// }
	// cout << endl;

	// newDs = ds.Slice(2, 3); // [2, 3)
	// for(int i = 0; i < ds.Count(); i++) {
	// 	int val = *(newDs + i);
	// 	if (val) {
	// 		cout << val  << endl;
	// 	} 
	// }

	// newDs = ds.Revert();
	// for(int i = 0; i < ds.Count(); i++) {
	// 	int val = *(newDs + i);
	// 	cout << val  << "\t";
	// }

	ds.Print();
	ds.DeleteByVal(4);
	ds.Print();
	// ds.Delete(1, 2); // [1,2)
	// ds.Print();
	// ds.Print(2, 4);


	return 0;
}

