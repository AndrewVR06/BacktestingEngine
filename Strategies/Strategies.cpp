// Strategies.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "Strategies.h"

#include <iostream>


Strategy::Strategy(std::string name)
{
	m_StrategyName = name;
}

Signal Strategy::tick()
{
	return Signal::BUY;
}

std::string Strategy::GetStrategyName() const
{
	return m_StrategyName;
}