#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "harvest.h"

class Fruit :public Harvest {
public:
	Fruit(const std::string name, const std::string color, const double weight) : Harvest(name, color, weight) {};
};