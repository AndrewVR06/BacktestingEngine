#include "pch.h"
#include "Interface.h"

Interface::Interface()
{
	m_Engine = std::make_unique<Engine>(Engine());
	m_StrategyInterface = std::make_unique<StrategyInterface>(StrategyInterface());
}

Interface::~Interface()
{
	if (m_StrategyList_CLinkage != nullptr)
	{
		auto list = m_StrategyInterface->GetStrategyList(); //race condition for m_Strategy? when does shared ptr free?

		for (unsigned int i = 0; i < list.size() + 1; i++)
		{
			delete m_StrategyList_CLinkage[i];
		}
		delete m_StrategyList_CLinkage;
	}
}

void Interface::AddHistoricalData(const char* path)
{
	m_Engine->addHistoricalData(path);
}

char** Interface::GetStrategyList()
{
	//If the list has not yet been created then create a new one. 
	if (m_StrategyList_CLinkage == nullptr)
	{
		auto list = m_StrategyInterface->GetStrategyList();
		int listSize = (int) list.size();
		m_StrategyList_CLinkage = new char* [listSize+1];
		
		for (int i = 0; i < listSize; i++)
		{
			m_StrategyList_CLinkage[i] = new char[list.at(i).length() + 1];
			strcpy_s(m_StrategyList_CLinkage[i], list.at(i).length() + 1, list.at(i).c_str());
		}

		///Include "end" as the last value of the list so that python knows to stop reading from array.
		m_StrategyList_CLinkage[listSize] = new char[4];
		strcpy_s(m_StrategyList_CLinkage[listSize], 4, "end");
	}	
	return m_StrategyList_CLinkage;
}

void Interface::BeginSimulation(const char* strategyName)
{
	Strategy* chosenStrategy = m_StrategyInterface->GetStrategy(strategyName);
	m_Engine->BeginSimulation(chosenStrategy);
}



