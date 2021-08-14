//Binary recursion looks like linear recursion but with 2 parrams input and calls back it 2 times.

int Fibonaci(int n)
{
	if(n <= 2)
		return 1;
	else
		return Fibonaci(n-1) + Fibonaci(n-2);
}