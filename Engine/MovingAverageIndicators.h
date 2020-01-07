#pragma once

/* This file defines all the different types of moving averages and their assocciated functionality. 
*/

#include "Indicator.h"
#include <iostream>

//Defines the Simple Moving average class indicator
class SMA : public Indicator
{
public:
	SMA(int);

	void PrintName() const override
	{
		std::cout << "SMA" << std::endl;
	}

	double operator[](int);
};

//Defines the Exponential Moving average class indicator
class EMA : public Indicator
{
	void PrintName() const override
	{
		std::cout << "SMA" << std::endl;
	}
};

//Defines the Moving average convergence divergence class indicator
class MACD : public Indicator
{
	void PrintName() const override
	{
		std::cout << "SMA" << std::endl;
	}
};

