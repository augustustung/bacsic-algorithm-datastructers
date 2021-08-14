//tail recursion is a special case of linear recursion.


//using Euclid in math
int gcd(int n, int m)
{
	if(m == n)
		return m;
	else if(m > n)
		return gcd(n, m-n);
	else
		return gcd(n-m, m);
}