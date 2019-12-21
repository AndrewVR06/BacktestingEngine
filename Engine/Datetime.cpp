#include "pch.h"
#include "Datetime.h"

#include <string>
#include <sstream>
#include <iostream>

void Datetime::addValue(std::string date)
{
	/* The assumption made on the string paramter are as follows:
	* x-x-x : Is assummed to by year-month-day. Assumed max number of characters = 10; (2019-05-12)
	* x-x-x x:m:s : Is assumed to be year-month-day hour:minute:second;
	These are the defaults to be used. May provided custom functionality later on
	*/

	// Form y-m-d
	if (date.length() <= 10)
	{
		std::vector<int> tokens;
		std::stringstream tokenize(date);
		std::string temp;

		while (std::getline(tokenize, temp, '-'))
		{
			tokens.emplace_back(std::stoi(temp));
		}
		m_DataValues.emplace_back(DateTimeStruct(tokens.at(0), tokens.at(1), tokens.at(2)));
	}

}

void Datetime::displayData() const
{
	for (auto it = m_DataValues.begin(); it != m_DataValues.end(); it++)
	{
		std::cout << it->m_Year << "-" << it->m_Month << "-" << it->m_Day << std::endl;
	}
}
