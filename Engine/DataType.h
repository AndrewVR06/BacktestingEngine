#pragma once

/* This class is used to store any measurement of data. This could be anything; such as open, close, median, high etc.. prices.
 * This is neccessary because we want the option to cache data once it has been read from a file. The cached data should then also be available to the front end.
 * So if the front end asks for the "open" prices then we are able to return it immediatly. This call will be done by name.
*/

#include <string>
#include <vector>

class DataType
{

public:

	DataType();

	DataType(std::string);

	std::string getDataTypeName() const
	{
		return m_DataTypeName;
	}

	virtual void addValue(std::string);

	virtual void displayData() const;

private:

	std::string m_DataTypeName;

	std::vector<float> m_DataValues;


};

