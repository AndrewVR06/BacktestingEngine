#pragma once

#include "Strategies.h"
#include "MovingAveragesStrategies.h"

#include <vector>
#include <memory>
#include <string>
#include <functional>
#include <unordered_map>

class StrategyInterface
{
public:

	std::vector<std::string> GetStrategyList();

private:

	/// External list that hold all functions and their names. All functions created in the implementation file need to be added here.
	std::vector<Strategy> m_StrategyList =
	{
		SMA5_over_SMA15("SMA5_over_SMA15"),
	};
	
private:
};
