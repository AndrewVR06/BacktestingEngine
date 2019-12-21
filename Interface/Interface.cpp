#include "pch.h"
#include "Interface.h"

Interface::Interface()
{
	m_Engine = std::make_unique<Engine>(Engine());
}
