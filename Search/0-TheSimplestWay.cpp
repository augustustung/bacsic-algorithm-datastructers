int find(int arr[], int m, int n)
{
	for(int i = 0; i < m; i++)
		if(arr[i] == n)
			return i;


	return 0;
}
