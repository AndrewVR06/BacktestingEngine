#pragma once

#include <memory>
#include <Windows.h>

#include "Engine.h"

class Interface
{
public:

	Interface();

	void AddHistoricalData(const char*);

private:

	std::unique_ptr<Engine> m_Engine = nullptr;

};

///Functions to export to  the Frontend
extern "C"
{
	__declspec(dllexport) Interface* CreateInterface();
	__declspec(dllexport) void AddHistoricalData(Interface*, const char*);
}

Interface* CreateInterface()
{
	return new Interface();
}

void AddHistoricalData(Interface* in, const char* path)
{
	in->AddHistoricalData(path);
}

