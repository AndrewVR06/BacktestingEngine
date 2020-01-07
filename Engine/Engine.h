#include <string>
#include <vector>
#include <memory>
#include <iostream>

#include "CSVReader.h"
#include "DataType.h"
#include "Strategies.h"

class Engine {
public:

	Engine(void);
	// TODO: add your methods here.

	void addHistoricalData(std::string path);

	void BeginSimulation(Strategy*);

	void SetSimulatorStrategy(Strategy*);

private:

	//2d array to cache historical data
	std::vector<std::shared_ptr<DataType>> m_CachedData;

	std::shared_ptr<Strategy> m_SimulatorStrategy;

	std::unique_ptr<CSVReader> m_CSVreader = nullptr;

};


