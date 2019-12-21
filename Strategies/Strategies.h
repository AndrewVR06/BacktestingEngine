#pragma once

#include <vector>
#include <memory>
#include <string>
#include <functional>

#include "TradingStrategies.h"

class Strategy
{
public:

private:

	std::vector<std::function<Signal(void)>> m_TradingStrategies =
	{
		SMA5_over_SMA15,
	};

};
