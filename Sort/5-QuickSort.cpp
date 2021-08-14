void QuickSort(int M[], int left, int right)
{
	if(left >= right)	return;
	int pivot = M[(left + right) / 2];
	int i = left;
	int j = right;
	do {
		while(M[i] < pivot)	i++;
		while(M[j] > pivot) j++;
		if(i <= j)
		{
			int temp = M[i];
			M[i] = M[j];
			M[j] = temp;
			i++;
			j--;
		}
	} while( i < j);
	QuickSort(M, left, j);
	QuickSort(M, i, right);
}