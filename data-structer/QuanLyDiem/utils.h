#ifndef mylib_h
#define mylib_h
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void NapDuLieu()
{
  ifstream fin("DL.tung");
  int N;
  fin>>N;
  for(int i = 0; i<N; i++)
  {
    fin.ignore();
    MonHoc m;
    getline(fin, m.maHocPhan);
    getline(fin, m.tenHocPhan);
    fin>>m.soTinChi;
    fin>>m.diem;
    ds.Add(m);
  }
  fin.close();
}

int ThucDon()
{
  cout<<"CHUONG TRINH QUAN LY DANH BA\n";
  cout<<"\t1. Danh sach\n";
  cout<<"\t2. Them moi\n";
  cout<<"\t3. Sua mon hoc\n";
  cout<<"\t4. Xoa mon hoc\n";
  cout<<"\t5. Tong ket\n";
  cout<<"\t0. Thoat\n";
  cout<<"Moi chon chuc nang: ";
  int chon;
  cin>>chon;
  return chon;
}

void HienThi()
{
  cout<<"\nSTT\tMa\tTen\tTin chi\tDiem\n";
  for(int i = 0; i<ds.Count(); i++)
  {
    MonHoc m = ds.Get(i+1);
    cout<<i+1<<"\t";
    cout<<m.maHocPhan<<"\t";  
    cout<<m.tenHocPhan<<"\t";  
    cout<<m.soTinChi<<"\t";  
    cout<<m.diem<<"\n";  
  }
  cout << endl;
}

void ThemMoi()
{
  MonHoc m;
  cin.ignore();
  cout<<"Nhap ma hoc phan: ";      
  getline(cin, m.maHocPhan);      
  cout<<"Nhap ten hoc phan: ";
  getline(cin, m.tenHocPhan);
  cout<<"Nhap so tin chi: ";
  cin >> m.soTinChi;
  cout<<"Nhap diem: ";
  cin >> m.diem; 
  ds.Add(m);
}

void GhiDuLieu()
{
  ofstream fout("DL.tung");
  fout<<ds.Count()<<endl;
  for(int i = 0; i < ds.Count(); i++)
  {
    MonHoc m = ds.Get(i+1);
    fout<<m.maHocPhan<<endl;
    fout<<m.tenHocPhan<<endl;
    fout<<m.soTinChi<<endl;
    fout<<m.diem<<endl;
  }
  fout.close();
}

// void TimKiem()
// {
//   string s;
//   cout<<"Nhap ma hoac ten mon hoc: ";
//   cin.ignore();
//   getline(cin, s);
//   bool f = false;
//   for(int i = 0; i<N; i++)
//   {
//     if (
//       m.maHocPhan.find(s) != string::npos || 
//       m.tenHocPhan.find(s) != string::npos
//     )
//     {
//       cout << i+1<<endl;
//       cout<<"Ma hoc phan: "<<m.maHocPhan<<endl;
//       cout<<"Ten hoc phan: "<<m.tenHocPhan<<endl;
//       cout<<"So tin chi: "<<m.soTinChi<<endl;
//       cout<<"Diem: "<<m.diem<<endl << endl;
//       f = true;
//     }
//   }
//   if (!f)
//     cout<<"Khong tim thay\n";
// }

void giuGiaTriCuString(string &giaTriMoi, string &giaTriCu) {
  if (giaTriMoi == "") {
    giaTriMoi = giaTriCu;
  }
}

void suaHocPhan() 
{
  string s;
  cout<<"Nhap ma mon hoc: ";
  cin.ignore();
  getline(cin, s);

  MonHoc capNhapMonHoc;
  bool f = false;
  int index;
  for(int i = 0; i<ds.Count(); i++)
  {
    MonHoc m = ds.Get(i+1);
    cout << "sad   " << m.maHocPhan << "   " << s << "   ";
    if (m.maHocPhan == s)
    {
      cout<<"Ma hoc phan ("<<m.maHocPhan<<"): ";
      cin.ignore();
      getline(cin, capNhapMonHoc.maHocPhan);
      giuGiaTriCuString(capNhapMonHoc.maHocPhan, m.maHocPhan);

      cout<<"Ten hoc phan ("<<m.tenHocPhan<<"): ";
      getline(cin, capNhapMonHoc.tenHocPhan);
      giuGiaTriCuString(capNhapMonHoc.tenHocPhan, m.tenHocPhan);

      cout<<"So tin chi ("<<m.soTinChi<<"): ";
      cin >> capNhapMonHoc.soTinChi;

      cout<<"Diem ("<<m.diem<<"): ";
      cin >> capNhapMonHoc.diem;

      f = true;
    }
  }
  if (!f) {
    cout<<"Khong tim thay\n";
  } else {
    ds.Update(index+1, capNhapMonHoc);
  }
}

void xoaHocPhan() {
  string s;
  cout<<"Nhap ma hoac ten mon hoc: ";
  cin.ignore();
  getline(cin, s);
  bool f = false;
  for(int i = 0; i<ds.Count(); i++)
  {
    MonHoc m = ds.Get(i+1);
    if (
      m.maHocPhan.find(s) != string::npos || 
      m.tenHocPhan.find(s) != string::npos
    )
    {
      cout<<"Xoa hoc phan co ma la: "<<m.maHocPhan<<endl;
      ds.Delete(i+1);
      f = true;
    }
  }
  if (!f) {
    cout<<"Khong tim thay\n";
  }
}

void tongKet() {
  HienThi();

  int tongSoTinChi = 0;
  int tongDiem = 0;
  for(int i = 0; i < ds.Count(); i++) {
    MonHoc m = ds.Get(i+1);
    tongSoTinChi += m.soTinChi;
    tongDiem += m.diem;
  }

  cout << "Tong so mon da hoc: " << ds.Count() << endl;
  cout << "Tong so tin chi: " << tongSoTinChi << endl;
  cout << "Diem trung binh: " << tongDiem / tongSoTinChi << endl;
}

#endif
