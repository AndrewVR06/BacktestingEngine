#pragma once

//#include "Strategies.h"
#include "MovingAveragesStrategies.h"

#include <vector>
#include <memory>
#include <string>
#include <functional>
#include <unordered_map>

class Strategy;

class StrategyInterface
{
public:

	std::vector<std::string> GetStrategyList();

	Strategy* GetStrategy(std::string name);

private:

	/// List that hold all functions and their names. All functions created in the implementation file need to be added here.
	std::vector<std::shared_ptr<Strategy>> m_StrategyList =
	{
		std::make_shared<SMA5_over_SMA15>("SMA5_over_SMA15"),
	};
	
};

