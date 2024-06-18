#pragma once
#include<iostream>
using namespace std;

class CVirus
{
protected:
	bool NhiemVirus;
public:
	CVirus();
	~CVirus();
	virtual double TiLeTuVong();
	virtual void TrieuChungNhe();
	virtual void TrieuChungNang();
	bool GetNhiemVirus();
	void SetNhiemVirus(int);
};

