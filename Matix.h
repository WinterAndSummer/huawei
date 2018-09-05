#pragma once

class CMatix
{
public:

	int m;//ÐÐ
	int n;//ÁÐ
	float *arr;

	float read(int i, int j);//¶Á
	bool write(int i, int j, float val);//Ð´
	CMatix();
	~CMatix();
	CMatix(int m, int n);

};

