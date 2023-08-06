#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "cultures.h"

class CherryTree :public Culture {
	int _harvQuant;
public:
	CherryTree(/*const std::string name,*/ const std::string size, const std::string color, int harvQuant) : Culture("CherryTree", size, color), _harvQuant(harvQuant) {};
	void printInfo()const;
	Harvest* harvestType() override;
};