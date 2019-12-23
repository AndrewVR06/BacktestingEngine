#pragma once
#include <vector>
#include <memory>
#include "DataType.h"

class Simulator
{
public:

	Simulator(std::vector<std::shared_ptr<DataType>> data);



private:

	std::vector<std::shared_ptr<DataType>> m_HistoricalData;

};

