#include "LinearReg.h"
#include <iostream>
#include "Matix.h"
#include "CMatric_Cal.h"
using namespace std;
LinearReg::LinearReg()
{
	a = 0;
	b = 0;
	c = 0;
	e = 0;
	d = 0;
}
LinearReg::~LinearReg()
{
}

double LinearReg::getA()
{
	return a;
}
double LinearReg::getB()
{
	return b;
}
double LinearReg::getC()
{
	return c;
}
double LinearReg::getD()
{
	return d;
}
double LinearReg::getE()
{
	return e;
}
void LinearReg::GradentDescent(vector<Point> pointG, int n)//梯队下降函数
{
	CMatix X(pointG.size(), 3);
	for (unsigned int i = 0; i < pointG.size(); i++)
	{
		X.write(i, 0, pointG[i].getx1()*pointG[i].getx1());
		X.write(i, 1, pointG[i].getx1());
		X.write(i, 2, 1);
	}

	CMatric_Cal ma;
	CMatix XT(3,pointG.size());//x的zhaunzhi
	ma.transpos(&X, &XT);
	CMatix XTX(3, 3);
	ma.multiply(&XT, &X, &XTX);
	CMatix XTX_(3, 3);
	ma.inverse(&XTX, &XTX_);
	CMatix XTX_XT(3, pointG.size());
	ma.multiply(&XTX_, &XT, &XTX_XT);
	CMatix XTX_XTy(3, 1);
	CMatix y(pointG.size(), 1);
	for (unsigned int i = 0; i < pointG.size(); i++)
	{
		y.write(i, 0, pointG[i].gety());
	}
	ma.multiply(&XTX_XT, &y, &XTX_XTy);
	a = XTX_XTy.read(0, 0);
	b = XTX_XTy.read(1, 0);
	c = XTX_XTy.read(2, 0);
} 

double  LinearReg::CostFuction(vector<Point> pointC, int n)
{
	double cost = 0;
	double hx = 0;
	for (int i = 0; i < n; i++)
	{
		//hx = a*pointC[i].getx1() + b*pointC[i].getx2() + c*pointC[i].getx3() + d*pointC[i].getx4() + e*pointC[i].getx5();
		hx = a*pointC[i].getx1()*pointC[i].getx1() + b*pointC[i].getx1()+c;
		cost += (hx - pointC[i].gety())*(hx - pointC[i].gety());
	}
	return cost / 2;
}
double LinearReg::Predict(int x1)
{
	double hx = a*x1*x1 + b*x1+c;
	//double hx = a*x1 + b;
	return hx;
}

double LinearReg::weight(double x, double xi, double k)
{
	//double t = -(x - xi)*(x - xi) / (2 * k*k);
	//double w = exp(t);
	return x;
}
