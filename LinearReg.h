#pragma once
#include <vector>
#include "Point.h"
using namespace std;
class LinearReg
{
private:
	double a, b, c, d, e;
	double lasta, lastb, lastc, lastd, laste;
	const double alpha = 0.001;
public:
	LinearReg();
	~LinearReg();
	double getA();
	double getB();
	double getC();
	double getD();
	double getE();
	void GradentDescent(vector<Point> pointG, int n);//ÌÝ¶ÓÏÂ1⁄2μo ̄Êý
    double CostFuction(vector<Point> pointC, int n);
	double Predict(int x1);
	double weight(double  x, double xi, double k);
};

