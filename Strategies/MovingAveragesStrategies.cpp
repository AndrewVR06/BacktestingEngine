#pragma once

/* All moving averages strategies implementations are found in the file. 
*/
#include "pch.h"
#include "TradingStrategies.h"
#include "Signal.h"

#include <unordered_map>
#include <functional>
#include <string>
#include <iostream>

/// External list that hold all functions and their names. All functions created in the implementation file need to be added here.
extern std::unordered_map<std::string, std::function<Signal(void)>> movingAveragesStrategiesList = 
{
	{"SMA5_over_SMA15", SMA5_over_SMA15}
};

Signal SMA5_over_SMA15()
{
	std::cout << "In strategy SMA5_over_SMA15" << std::endl;
	return Signal::HOLD;
}