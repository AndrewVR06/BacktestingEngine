#pragma once

#include "Signal.h"
#include "Indicator.h"

#include <vector>
#include <memory>
#include <string>
#include <functional>
#include <unordered_map>

class Strategy
{
public:

	Strategy(std::string);

	virtual Signal tick();

	virtual std::string GetStrategyName() const;

private:

	std::string m_StrategyName;

	std::vector<Indicator> m_IndicatorList;

};
