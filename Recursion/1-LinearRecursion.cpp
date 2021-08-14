//linear recursive: the function calls back it 1 time.

int factorial(int n)
{
	if(n == 0)
		return 1;
	else return n * factorial(n-1);
}