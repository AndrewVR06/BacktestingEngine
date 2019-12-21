// Engine.cpp : Defines the exported functions for the DLL.
#include "pch.h"
#include "Engine.h"
#include "CSVReader.h"

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

Engine::Engine()
{
	m_CSVreader = std::make_unique<CSVReader>(CSVReader());
}

void Engine::addHistoricalData(std::string path)
{
	m_CSVreader->readCSV(m_CachedData, path);
	for (auto it = m_CachedData.begin(); it != m_CachedData.end(); it++)
	{
		//it->get()->displayData();
	}

	std::cout << __func__ << std::endl;
}


