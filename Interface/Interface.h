#pragma once

#include "Engine.h"
#include "Strategies.h"

#include <memory>
#include <Windows.h>
#include <string>
#include <vector>

class Interface
{
public:

	Interface();

	~Interface();

	void AddHistoricalData(const char*);

	char** GetStrategyList();

private:

	std::unique_ptr<Engine> m_Engine = nullptr;

	std::unique_ptr<Strategy> m_Strategy = nullptr;

	// Variable that stores the strategy list without using anything within the std;
	char** m_StrategyList_CLinkage;

};

///Functions to export to  the Frontend
extern "C"
{
	__declspec(dllexport) Interface* CreateInterface();
	__declspec(dllexport) void AddHistoricalData(Interface*, const char*);
	__declspec(dllexport) char ** GetStrategyList(Interface*);
}

Interface* CreateInterface()
{
	return new Interface();
}

void AddHistoricalData(Interface* in, const char* path)
{
	in->AddHistoricalData(path);
}

char** GetStrategyList(Interface* in)
{
	return in->GetStrategyList();
}



