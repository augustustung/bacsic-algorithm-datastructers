void InterChangeSort(int M[], int n)
{
	int i, j;
	for(int i = 0; i < n-1; i++)
	{
		for(j = i+1; j < n;j++)
		{
			if(M[j] < M[i])
			{
				int temp = M[i];
				M[i] = M[j];
				M[j] = temp;
			}
		}
	}
}