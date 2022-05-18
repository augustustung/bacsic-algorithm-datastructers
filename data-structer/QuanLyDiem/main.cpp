#include <iostream>
#include <string>
#include "monhoc.h"
#include "list.h"
using namespace std;

List<MonHoc> ds;
#include "utils.h"

int main() {
	NapDuLieu();
  int chon;
  do
  {
    chon = ThucDon();
    switch (chon)
    {
      case 1:
        HienThi();
      break;
      case 2:
        ThemMoi();
        break;
      case 3:
        suaHocPhan();     
        break;
      case 4:
        xoaHocPhan();
        break;
      case 5:
        tongKet();
        break;
    }
    cout<<"Nhan ky tu bat ky roi enter de tiep tuc";
    char ch;
    cin>>ch;
  } while (chon != 0);
  GhiDuLieu();
	return 0;
}
