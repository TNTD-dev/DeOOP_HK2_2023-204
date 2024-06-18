#include "CVatChu.h"

double RandomDouble()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<double> unif(0, 1);
	return unif(gen);
}

void CVatChu::Nhap()
{
	cout << "Nhap ma so: ";
	cin >> MaSo;
	cout << "Kha nang mien dich (1. Thap, 2. Trung Binh, 3. Cao): ";
	cin >> MienDich;
	cout << "Nhap loai virus bi nhiem (0. Khong nhiem, 1. Nhiem ca 3 virus): ";
	int loai;
	cin >> loai;

	NhiemVirus[0] = new CCovid;
	NhiemVirus[1] = new CEbola;
	NhiemVirus[2] = new CHiv;
	if (loai == 1)
	{
		for (int i = 0; i < 3; i++)
			NhiemVirus[i]->SetNhiemVirus(1);
	}
	else
	{
		for (int i = 0; i < 3; i++)
			NhiemVirus[i]->SetNhiemVirus(0);
	}
	cout << "Nhap tiem vacxin phong ngua (0. Chua, 1. Roi): ";
	int x;
	cin >> x;
	TiemVacXin = x;
}
double x = RandomDouble();
void CVatChu::Xuat()
{
	cout << "Ma so: " << MaSo << endl;
	if (!TiemVacXin)
	{
		if (MienDich == 3)
		{
			if (x>=0.5) cout << "Khong co trieu chung" << endl;
			else if (x >= 0.35 && x < 0.5)
			{
				for (int i = 0; i < 3; i++)
				{
					NhiemVirus[i]->TrieuChungNhe();
				}
			}
			else if (x >= 0.15 && x < 0.35 || x < 0.15)
			{
				for (int i = 0; i < 3; i++)
				{
					NhiemVirus[i]->TrieuChungNang();
				}
			}
		}
		else if (MienDich == 2)
		{
			if (x >= 0.5)
			{
				for (int i = 0; i < 3; i++)
				{
					NhiemVirus[i]->TrieuChungNang();
				}
			}
			else if (x >= 0.4 && x < 0.5)
			{
				for (int i = 0; i < 3; i++)
				{
					NhiemVirus[i]->TrieuChungNhe();
				}
			}
			else if (x >= 0.1 && x < 0.4 || x < 0.1)
			{
				cout << "Khong co trieu chung" << endl;
			}
		}
		else if (MienDich == 1)
		{
			if (x >= 0.8)
			{
				for (int i = 0; i < 3; i++)
				{
					NhiemVirus[i]->TrieuChungNang();
				}
			}
			else if (x >= 0.15 && x < 0.8)
			{
				for (int i = 0; i < 3; i++)
				{
					NhiemVirus[i]->TrieuChungNhe();
				}
			}
			else if (x >= 0.05 && x < 0.15 || x < 0.05)
			{
				cout << "Khong co trieu chung" << endl;
			}
		}
	}
	else
	{
		if (MienDich == 3)
		{
			if (x >= 0.7) cout << "Khong co trieu chung" << endl;
			else if (x >= 0.25 && x < 0.7)
			{
				for (int i = 0; i < 3; i++)
				{
					NhiemVirus[i]->TrieuChungNhe();
				}
			}
			else if (x >= 0.05 && x < 0.25 || x < 0.05)
			{
				for (int i = 0; i < 3; i++)
				{
					NhiemVirus[i]->TrieuChungNang();
				}
			}
		}
		else if (MienDich == 2)
		{
			if (x >= 0.5)
			{
				for (int i = 0; i < 3; i++)
				{
					NhiemVirus[i]->TrieuChungNhe();
				}
			}
			else if (x >= 0.3 && x < 0.5)
			{
				for (int i = 0; i < 3; i++)
				{
					NhiemVirus[i]->TrieuChungNang();
				}
			}
			else if (x >= 0.2 && x < 0.3 || x < 0.2)
			{
				cout << "Khong co trieu chung" << endl;
			}
		}
		else if (MienDich == 1)
		{
			if (x >= 0.5)
			{
				for (int i = 0; i < 3; i++)
				{
					NhiemVirus[i]->TrieuChungNang();
				}
			}
			else if (x >= 0.4 && x < 0.5)
			{
				for (int i = 0; i < 3; i++)
				{
					NhiemVirus[i]->TrieuChungNhe();
				}
			}
			else if (x >= 0.1 && x < 0.4 || x < 0.05)
			{
				cout << "Khong co trieu chung" << endl;
			}
		}
	}
	
}
double t = RandomDouble();
bool CVatChu::TuVong()
{
	if (!TiemVacXin)
	{
		if (MienDich == 3)
		{
			for (int i = 0; i < 3; i++)
			{
				if (NhiemVirus[i]->TiLeTuVong() * 0.5 < t) return true;
			}
		}
		else if (MienDich == 2)
		{
			for (int i = 0; i < 3; i++)
			{
				if (NhiemVirus[i]->TiLeTuVong() * 0.7 < t) return true;
			}
		}
		else if (MienDich == 1)
		{
			for (int i = 0; i < 3; i++)
			{
				if (NhiemVirus[i]->TiLeTuVong() * 1.0 < t) return true;
			}
		}
	}
	else
	{
		if (MienDich == 3)
		{
			for (int i = 0; i < 3; i++)
			{
				if (NhiemVirus[i]->TiLeTuVong() * 0.4 < t) return true;
			}
		}
		else if (MienDich == 2)
		{
			for (int i = 0; i < 3; i++)
			{
				if (NhiemVirus[i]->TiLeTuVong() * 0.6 < t) return true;
			}
		}
		else if (MienDich == 1)
		{
			for (int i = 0; i < 3; i++)
			{
				if (NhiemVirus[i]->TiLeTuVong() * 0.8 < t) return true;
			}
		}
	}
	return false;
	
}

int CVatChu::SoLuongTrieuChungNang()
{
	if (!TiemVacXin)
	{
		if (MienDich == 3 && (x >= 0.15 && x < 0.35 || x < 0.15)) return 1;
		else if (MienDich == 2 && x >= 0.5) return 1;
		else if (MienDich == 1 && x >= 0.8) return 1;
	}
	else
	{
		if (MienDich == 3 && (x >= 0.05 && x < 0.25 || x < 0.05)) return 1;
		else if (MienDich == 2 && (x >= 0.3 && x < 0.5)) return 1;
		else if (MienDich == 1 && x >= 0.5) return 1;
	}
	return 0;
}

int CVatChu::SoLuongTuVong()
{
	if (!TiemVacXin)
	{
		if (MienDich == 3)
		{
			for (int i = 0; i < 3; i++)
			{
				if (NhiemVirus[i]->TiLeTuVong() * 0.5 < t) return 1;
			}
		}
		else if (MienDich == 2)
		{
			for (int i = 0; i < 3; i++)
			{
				if (NhiemVirus[i]->TiLeTuVong() * 0.7 < t) return 1;
			}
		}
		else if (MienDich == 1)
		{
			for (int i = 0; i < 3; i++)
			{
				if (NhiemVirus[i]->TiLeTuVong() * 1.0 < t) return 1;
			}
		}
	}
	else
	{
		if (MienDich == 3)
		{
			for (int i = 0; i < 3; i++)
			{
				if (NhiemVirus[i]->TiLeTuVong() * 0.4 < t) return 1;
			}
		}
		else if (MienDich == 2)
		{
			for (int i = 0; i < 3; i++)
			{
				if (NhiemVirus[i]->TiLeTuVong() * 0.6 < t) return 1;
			}
		}
		else if (MienDich == 1)
		{
			for (int i = 0; i < 3; i++)
			{
				if (NhiemVirus[i]->TiLeTuVong() * 0.8 < t) return 1;
			}
		}
	}
	return 0;
}
