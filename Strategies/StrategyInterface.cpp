#include "pch.h"
#include "framework.h"
#include "StrategyInterface.h"

#include <iostream>


std::vector<std::string> StrategyInterface::GetStrategyList()
{
	std::vector<std::string> nameList;
	for (auto it = m_StrategyList.begin(); it != m_StrategyList.end(); it++)
	{
		nameList.emplace_back(it->GetStrategyName());
	}
	return nameList;
}
