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
	SMA5_over_SMA15(std::string name)
	{
		m_StrategyName = name;

		m_IndicatorList.emplace_back(sma_5);
		m_IndicatorList.emplace_back(sma_15);
	}

	Signal tick() override;

	virtual std::string GetStrategyName() const override;

	virtual std::unique_ptr<std::vector<std::shared_ptr<Indicator>>> GetIndicators() const override;

private:
	///List all indicators used.
	std::shared_ptr<SMA> sma_5 = std::make_shared<SMA>(SMA(5));
	std::shared_ptr<SMA> sma_15 = std::make_shared<SMA>(SMA(15));

	std::vector<std::shared_ptr<Indicator>> m_IndicatorList;

	std::string m_StrategyName;

	std::string ticker;

};


