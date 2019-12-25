#pragma once

/* Function definations for strategies using moving averages
*/

#include "Signal.h"
#include "Strategies.h"
#include "MovingAverageIndicators.h"

#include <memory>
#include <string>

class SMA5_over_SMA15 : public Strategy
{
public:
	SMA5_over_SMA15(std::string name) : Strategy(name) 
	{
	}
	Signal tick() override;

private:
	///List all indicators used.
	//Indicator* sma_5 = new SMA(5);
	std::unique_ptr<SMA> sma_5 = std::make_unique<SMA>(SMA(5));
};


