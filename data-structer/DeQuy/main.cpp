#include <iostream>
using namespace std;

void F(int N)
{
  if (N >= 1)
  {
    cout<<"Hello\n";
    cout<<"Hi\n";
    F(N-1);
  }
}

int GiaiThua(int N)
{
  if (N == 0)
    return 1;
  return N * GiaiThua(N-1);
}

int HaiMu(int N)
{
  if(N==0)
    return 1;
  return 2*HaiMu(N-1);
}

int Fib(int N)
{
  if(N==0)
    return 0;
  if(N==1)
    return 1;
  return Fib(N-1)+Fib(N-2);
}

void ThapHaNoi(int N, char c1, char c2, char c3)
{
  if(N == 1)
  {
    cout<<c1<<" --> "<<c3<<endl;
  }
  else
  {
    ThapHaNoi(N-1 ,c1 ,c3 ,c2);
    ThapHaNoi(1 ,c1 ,c2 ,c3);
    ThapHaNoi(N-1 ,c2 ,c1 ,c3);
  }
}

int a[100];

void SinhXauNhiPhan(int x, int a[], int N)
{
  if(x>N)
  {
    for(int i=0;i<N;i++)
      cout<<a[i];
    cout<<endl;
  }
  else
  {
    // a[x-1] = 0;
    // SinhXauNhiPhan(x+1, a ,N);
    // a[x-1] = 1;
    // SinhXauNhiPhan(x+1, a, N);
    for(int i=0;i<=8;i++)
    {
      a[x-1]=i;
      SinhXauNhiPhan(x+1, a, N);
    }
  }
}


void SinhXauThapLucPhan(int x, int a[], int N)
{
  if(x>N)
  {
    for(int i=0;i<N;i++)
      if(a[i]<9)
        cout<<a[i];
      else
        cout<<char('A' + a[i]-10);
    cout<<endl;
  }
  else
  {
    for(int i=0;i<=8;i++)
    {
      a[x-1]=i;
      SinhXauThapLucPhan(x+1, a, N);
    }
  }
}

//*BTVN: cho chữ cái -> tạo tất cả xâu 
char q[100];
void SinhXauKyTu(int x, char q[], int N)
{
  string kytu="AZM14";
  if(x>N)
  {
    for(int i=0;i<N;i++)
      cout<<q[i];
    cout<<endl;
  }
  else
  {
    for(int i=0;i<kytu.length();i++)
    {
      q[x-1]=kytu[i];
      SinhXauKyTu(x+1, q, N);
    }
  }
}

int main() 
{
  int N;
  cout<<"Nhap N = ";
  cin>>N;
  // cout<<N<<"! = "<<GiaiThua(N)<<endl;
  //cout<<HaiMu(N)<<endl;
  //cout<<Fib(N)<<endl;

  //ThapHaNoi(N, "1", "2", "3");

  //SinhXauNhiPhan(1 ,a, N);
  SinhXauThapLucPhan(1 ,a, N);
  //SinhXauKyTu(1, q, N);
}