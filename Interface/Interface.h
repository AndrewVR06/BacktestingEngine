#pragma once

#include <memory>

#include "Engine.h"

class Interface
{
public:

	Interface();

private:

	int t = 3;
	std::unique_ptr<Engine> m_Engine = nullptr;

};

