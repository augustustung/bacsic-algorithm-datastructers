
bool isEven(int n)
{
	if(n == 0)	return true;
	else return isOdd(n-1);
}

bool isOdd(int m)
{
	return !isEven(m);
}