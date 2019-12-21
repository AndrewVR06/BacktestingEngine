#pragma once
/* Holds all the trading strategies used.
*  
*  Each time a strategy is created, the signatures needs to be added here. All strategies MUST return the enum Signal type found in Signal.h
*/

#include <string>

#include "Signal.h"


Signal SMA5_over_SMA15();

