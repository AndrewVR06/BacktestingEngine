// Strategies.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "Strategies.h"

#include <iostream>


std::vector<std::string> Strategy::GetStrategyList()
{
	std::vector<std::string> nameList;
	for (auto it = m_StrategyList.begin(); it != m_StrategyList.end(); it++)
	{
		nameList.emplace_back(it->first);
	}
	return nameList;
}