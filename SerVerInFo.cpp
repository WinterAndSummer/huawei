#include "SerVerInFo.h"


SerVerInFo::SerVerInFo()
{
}


SerVerInFo::~SerVerInFo()
{
}

float SerVerInFo::getK_CM()
{
	return (float)AvailableMem / AvailableCpu;
}