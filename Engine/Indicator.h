#pragma once

class Indicator
{
public:

	Indicator(int period) : m_Period(period) {}

	virtual double operator[](int) { return 0; }

private:
	
	int m_Period;
};

