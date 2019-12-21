#include "pch.h"
#include "DataType.h"

#include <string>
#include <iostream>

DataType::DataType()
{
}

DataType::DataType(std::string name)
{
	m_DataTypeName = name;
}

void DataType::addValue(std::string value)
{
	m_DataValues.emplace_back(std::stof(value));
}

void DataType::displayData() const
{
	std::cout << m_DataTypeName << std::endl;
	for (auto it = m_DataValues.begin(); it != m_DataValues.end(); it++)
	{
		std::cout << *it << ",";
	}
	std::cout << std::endl << std::endl;
}
