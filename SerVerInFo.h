#pragma once
#include <vector>
using namespace std;
class SerVerInFo
{
public:
	SerVerInFo();
	~SerVerInFo();
	vector<int> fpFlavor;
	int cpu;
	int mem;
	int AvailableCpu;
	int AvailableMem;
	float getK_CM();
};



