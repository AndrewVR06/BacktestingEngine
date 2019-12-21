#include "pch.h"
#include "CSVReader.h"
#include "Datetime.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

CSVReader::CSVReader()
{
}

void CSVReader::readCSV(std::vector<std::shared_ptr<DataType>>& cachedData, std::string path)
{
	std::ifstream fin;
	std::string line, temp;

	fin.open(path, std::fstream::in);

	/* Lets first get the order that the values are presented in. Expected here is "open" , "close" , "high" ...
	*  This will determine the order of the pointers within the cachedData array and thus affect the way in which
	*  we save data.
	*/
	std::getline(fin, line);
	std::stringstream linestream(line);
	std::string value;

	while (std::getline(linestream, value, ','))
	{
		std::transform(value.begin(), value.end(), value.begin(), std::tolower);
		value.erase(std::remove(value.begin(), value.end(), '\"'), value.end());

		// check for "datetime" as that is the only data with a different type.
		if (value == "datetime")
		{
			std::shared_ptr<DataType> datetime = std::make_shared<Datetime>(Datetime());
			cachedData.emplace_back(datetime);
		}
		else
		{
			std::shared_ptr<DataType> newData = std::make_shared<DataType>(DataType(value));
			cachedData.emplace_back(newData);
		}
	}

	/* Now we attempt to read the rest of the file. The order of the data is already determined by the process above. We need to
	*  simply iterate through the data and save it into the cached array.
	*/
	std::getline(fin, line);
	while (line != "")
	{
		std::stringstream linestream(line);
		std::string value;

		auto it = cachedData.begin();

		while (std::getline(linestream, value, ','))
		{
			it->get()->addValue(value);
			it++;
		}
		std::getline(fin, line);
	}
	fin.close();
}
