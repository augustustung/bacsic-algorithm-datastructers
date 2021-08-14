//call the argument of the function

int ackman(int m, int n)
{
	if(m==0)	return n+1;
	else if(n==0)	return ackman(m-1,1);
	else	return ackman(m-1, ackman(m, n-1));
}