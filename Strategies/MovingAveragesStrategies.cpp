#pragma once

/* All moving averages strategies implementations are found in the file. 
*  In all functions, any instantiations of indicators need to be preceeded by the storage type "static"
*/
#include "pch.h"
#include "MovingAveragesStrategies.h"
#include "Signal.h"
//#include "MovingAverage.h" //imported from Engine. Defines all moving average indicators.

#include <string>
#include <iostream>

Signal SMA5_over_SMA15::tick()
{
	std::cout << "tick" << std::endl;
	return Signal::BUY;
}

std::string SMA5_over_SMA15::GetStrategyName() const
{
	return m_StrategyName;
}
