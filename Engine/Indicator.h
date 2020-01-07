#pragma once

class Indicator
{
public:

	virtual void PrintName() const = 0;

protected:
	
	int m_Period;
};

