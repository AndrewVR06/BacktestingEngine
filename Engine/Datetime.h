#pragma once

/* Specialised version of DataType. This will be used to house the datetime of all values. Date and time comparisons functions will be provided here.
*/

#include "DataType.h"
#include "DataFrequency.h"

struct DateTimeStruct
{
	DateTimeStruct() : m_Year(0), m_Month(0), m_Day(0), m_Hour(0), m_Minute(0), m_Second(0)
	{
	}

	DateTimeStruct(int year, int month, int day) : m_Year(year), m_Month(month), m_Day(day), m_Hour(0), m_Minute(0), m_Second(0)
	{
	}

	DateTimeStruct(int year, int month, int day, int hour, int minute, int second) : m_Year(year), m_Month(month), m_Day(day), m_Hour(hour), m_Minute(minute), m_Second(second)
	{
	}

	DateTimeStruct(const DateTimeStruct& rhs)
	{
		m_Year = rhs.m_Year;
		m_Month = rhs.m_Month;
		m_Day = rhs.m_Day;

		m_Hour = rhs.m_Hour;
		m_Minute = rhs.m_Minute;
		m_Second = rhs.m_Second;
	}

	friend DateTimeStruct operator-(const DateTimeStruct& lhs, const DateTimeStruct& rhs)
	{
		DateTimeStruct temp;
		temp.m_Year = lhs.m_Year - rhs.m_Year;
		temp.m_Month = lhs.m_Month - rhs.m_Month;
		temp.m_Day = lhs.m_Day - rhs.m_Day;

		temp.m_Hour = lhs.m_Hour - rhs.m_Hour;
		temp.m_Minute = lhs.m_Minute - rhs.m_Minute;
		temp.m_Second = lhs.m_Second - rhs.m_Second;

		return temp;
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

	DataFrequency GetIntradataPeriod() const;

private:

	std::vector<DateTimeStruct> m_DataValues;

};

