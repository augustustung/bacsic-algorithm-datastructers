#include <iostream>
using namespace std;
#include "list.h"

int main()
{
	List<int> ds;
	for (int i = 0; i < 10; i++)
	{
		ds.Add(i + 1);
	}
	// int arr[7] = {2,3,4,5,6,7,8};
	// ds.Concat(arr, 7);
	ds.Println();
	cout << ds.Count() << endl;

	// ds.Delete(3);
	// cout << ds.Count() << endl;
	// ds.Println();


	
	ds.Insert(1, 100);
	ds.Println();
	ds.Insert(3, 100);
	ds.Println();
	ds.Insert(8, 100);
	ds.Println();
	ds.Insert(14, 100);
	ds.Println();
	ds.Insert(13, 100);
	ds.Println();
	cout << ds.Count() << endl;
	
	// ds.Swap(3, 5);
	// ds.Println();

	// cout << ds.findFirstIndex(3) << endl;
	// cout << ds.findLastIndex(5) << endl;

	// ds.Replace(3, 1000);
	// ds.Println();
	// ds.Add(1000);
	// ds.Replace(3, 5, 1000);
	// ds.Println();
	// ds.DeleteByVal(1000);

	// ds.Delete(3, 5); // [start, end)
	// ds.Println();
	// ds.Count();


	// ds.Println();
	// cout << ds.Count(1000) << endl;

	// cout << ds.Some(3) << endl;

	// ds.Println(3, 5);
	// int *newDs;
	// newDs = ds.Find(3, 9); // min max
	// for(int i = 0; i < ds.Count(); i++) {
	// 	int val = *(newDs + i);
	// 	if (val) {
	// 		cout << val  << "\t";
	// 	} 
	// }
	// cout << endl;
	// ds.Replace(6, 8, 5);
	// newDs = ds.Find(3, 9, 5); // (min, max, value)
	// for(int i = 0; i < ds.Count(); i++) {
	// 	int val = *(newDs + i);
	// 	if (val) {
	// 		cout << val  << "\t";
	// 	} 
	// }
	// cout << endl;
	// newDs = ds.Slice(3, 9); // (startPos, endPos)
	// newDs = ds.Slice(3); // (startPos)
	// for(int i = 0; i < ds.Count(); i++) {
	// 	int val = *(newDs + i);
	// 	if (val) {
	// 		cout << val  << "\t";
	// 	} 
	// }

	return 0;
}