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

	virtual Signal tick() = 0;

	virtual std::string GetStrategyName() const = 0;

	virtual std::unique_ptr<std::vector<std::shared_ptr<Indicator>>> GetIndicators() const = 0;

protected:
	std::string StrategyName;
};
