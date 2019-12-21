#pragma once

/* Specialised version of DataType. This will be used to house the datetime of all values. Date and time comparisons functions will be provided here.
*/

#include "DataType.h"

struct DateTimeStruct
{

	DateTimeStruct(int year, int month, int day) : m_Year(year), m_Month(month), m_Day(day), m_Hour(0), m_Minute(0), m_Second(0)
	{
	}

	DateTimeStruct(int year, int month, int day, int hour, int minute, int second) : m_Year(year), m_Month(month), m_Day(day), m_Hour(hour), m_Minute(minute), m_Second(second)
	{
	}

	int m_Year;
	int m_Month;
	int m_Day;

	int m_Hour;
	int m_Minute;
	int m_Second;
};


class Datetime : public DataType
{
public:

	void addValue(std::string) override;

	void displayData() const override;

private:

	std::vector<DateTimeStruct> m_DataValues;

};

