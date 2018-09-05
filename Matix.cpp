#include "Matix.h"
using namespace std;
CMatix::CMatix()
{
}


CMatix::~CMatix()
{
	delete[]arr;
}
float CMatix::read(int i, int j)
{
	return *(arr + i*n + j);
}
bool CMatix::write(int i, int j, float val)
{
	*(arr + i*n + j) = val;
	return true;
}

CMatix::CMatix(int m, int n)
{
	arr = new float[n*m];
	this->m = m;
	this->n = n;
}

