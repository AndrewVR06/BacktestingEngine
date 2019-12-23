#include "pch.h"
#include "MovingAverage.h"

SMA::SMA(int period) : Indicator(period)
{
}

double SMA::operator[](int index) 
{
	return 0.1;
}
