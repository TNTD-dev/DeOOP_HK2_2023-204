#include"CVatChu.h"

int main()
{
	//Chua tiem vacxin
	CVatChu ds[100];
	int n;
	cout << "Nhap so luong vat chu 1: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap vat chu thu " << i + 1 << ":"<<endl;
		ds[i].Nhap();
	}
	for (int i = 0; i < n; i++)
	{
		cout << "Vat chu thu " << i + 1 << ":" << endl;
		ds[i].Xuat();
		if (ds[i].TuVong()) cout << "Vat chu thu " << i + 1 << "bi tu vong!" << endl;
	}

	cout << endl;
	//Tiem vacxin
	CVatChu ds2[100];
	int m;
	cout << "Nhap so luong vat chu 2: ";
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cout << "Nhap vat chu thu " << i + 1 << ":" << endl;
		ds2[i].Nhap();
	}
	int nang = 0;
	int chet = 0;
	for (int i = 0; i < m; i++)
	{
		nang += ds[i].SoLuongTrieuChungNang();
		chet += ds[i].SoLuongTuVong();
	}
	cout << "So luong nguoi bi trieu chung nang: " << nang << endl;
	cout << "So luong nguoi tu vong: " << chet << endl;

	return 0;
}