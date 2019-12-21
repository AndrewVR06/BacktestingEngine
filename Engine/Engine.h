#include <string>
#include <vector>
#include <memory>
#include <iostream>

#include "CSVReader.h"
#include "DataType.h"
#include "Simulator.h"

class Engine {
public:

	Engine(void);
	// TODO: add your methods here.

	void addHistoricalData(std::string path);

private:

	//2d array to cache historical data
	std::vector<std::shared_ptr<DataType>> m_CachedData;

	//Pointer to the class that shall perform the simulation
	std::unique_ptr<Simulator> m_Simulator = nullptr;

	std::unique_ptr<CSVReader> m_CSVreader = nullptr;

};


