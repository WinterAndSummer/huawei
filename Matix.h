#pragma once

class CMatix
{
public:

	int m;//��
	int n;//��
	float *arr;

	float read(int i, int j);//��
	bool write(int i, int j, float val);//д
	CMatix();
	~CMatix();
	CMatix(int m, int n);

};

