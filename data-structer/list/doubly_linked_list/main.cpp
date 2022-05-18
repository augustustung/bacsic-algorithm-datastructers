#include<iostream>
using namespace std;
#include "list.h"

int main()
{
	List<int> ds;
	for (int i = 1; i <= 10; i++)
	{
		ds.Add(i);
	}
	ds.Println();
	// ds.Delete(3);
	// ds.Println();
	// ds.Replace(2, 6);
	// ds.Replace(3, 6);
	// ds.Replace(4, 6);
	// ds.DeleteByVal(6);
	// ds.Println();

	ds.Insert(1, 100);
	ds.Insert(ds.Count(), 100);
	ds.Insert(3, 100);
	ds.Println();
	return 0;
}