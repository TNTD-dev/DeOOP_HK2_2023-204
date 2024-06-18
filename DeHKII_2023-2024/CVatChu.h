#pragma once
#include"CCovid.h"
#include"CEbola.h"
#include"CHiv.h"
#include<random>

class CVatChu
{
private:
	string MaSo;
	int MienDich;
	CVirus* NhiemVirus[3];
	bool TiemVacXin;
public:
	void Nhap();
	void Xuat();
	bool TuVong();
	int SoLuongTrieuChungNang();
	int SoLuongTuVong();
};

