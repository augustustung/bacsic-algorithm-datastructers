#include <iostream>
using namespace std;
#include "list.h"

int main()
{
	List<int> ds(10, 100);
	// for (int i = 0; i < 10; i++)
	// {
	// 	ds.Add(i + 1);
	// }
	ds.Println();
	cout << ds.Count() << endl;

	// ds.Delete(3);
	// cout << ds.Count() << endl;
	// ds.Println();


	
	// ds.Insert(4, 100);
	// ds.Println();
	// cout << ds.Count() << endl;

	cout << ds.FindFirstIndex(3) << endl;
	cout << ds.FindLastIndex(100) << endl;

	// ds.Replace(3, 1000);
	// ds.Println();

	// cout << ds.Some(3) << endl;
	return 0;
}