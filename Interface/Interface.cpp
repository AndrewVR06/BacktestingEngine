#include "pch.h"
#include "Interface.h"

Interface::Interface()
{
	m_Engine = std::make_unique<Engine>(Engine());
}

void Interface::AddHistoricalData(const char* path)
{
	m_Engine->addHistoricalData(path);
}
