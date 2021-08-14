void InsertSort(int M[], int n)
{
	int pos = 0;
	int x;
	for(int i = 0; i < n; i++)
	{
		x = M[i];
		for(pos = i; (pos > 0) && (M[pos-1] > x); pos--)
		{
			M[pos] = M[pos - 1];
		}
		M[pos] = x;
	}
}
