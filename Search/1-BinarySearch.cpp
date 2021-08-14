int BinarySearch(int arr[], int n, int m)
{
	int start = 0;
	int end = n-1;
	int middle;
	do
	{
		middle =  (end+start)/2;
		if(arr[middle] == m)
			return middle;
		else if(arr[middle] > m)
			end = middle-1;
		else 
			start = middle + 1;
	} while(start <= end);
}