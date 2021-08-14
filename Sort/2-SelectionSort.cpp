void SelectionSort(int M[], int n)
{
	int min;
	for(int i = 0; i<n-1; i++)
	{
		min = i;
		for(int j = i+1; j < n; j++)
		{
			if(M[j] < M[min])
				min = j;
		}
		if(min != i)
		{
			int temp = M[i];
			M[i] = M[min];
			M[min] = temp;
		}
	}
}