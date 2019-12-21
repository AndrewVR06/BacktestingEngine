#pragma once

#include <memory>
#include <string>
#include <vector>

class DataType;

class CSVReader
{

public:

	CSVReader();

	void readCSV(std::vector<std::shared_ptr<DataType>>& cachedData, std::string path);

private:


};

