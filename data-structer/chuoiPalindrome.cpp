#include <iostream>
#include <string>
using namespace std;
string Reverse(string s, int N)

{
	string temp(1, s[N-1]);
	if(N==1)
	{
		return temp;
	}
	else
	{
		return temp+ Reverse(s,N-1);
	}
}
int main() {
  string a;
	string b;
	// a="racecar";
	// cout<<a<<endl;
	// b= Reverse(a,a.length());
	

	a="able was i ere i saw elba";
	cout<<a<<endl;
	b= Reverse(a,a.length());
	if(a==b)
	{
		cout<<"a là chuỗi palindrome "<<endl;
	}
	else
		cout<<"a không là chuỗi palindrome "<<endl;