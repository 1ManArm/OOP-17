#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "cultures.h"

class CherryTree :public Culture {
	std::string currentCultureClassName = "Cherry Tree";
	size_t remainingFruits = 0;
public:
	CherryTree(size_t size, /*const std::string size,*/ const std::string color, int harvQuant) : Culture("CherryTree", size, color), _harvQuant(harvQuant) {};
	void printInfo()const;
	Harvest* harvestType() override;

	void info() override {
		Culture::info();
		std::cout << "\n" << _currentCultureClassName;
		std::cout << "\nОстаток " << _remainingHarvest;

	}

	Harvest* getHarvest() override
	{
		if (_remainingHarvest <= 0) return nullptr;
		Harvest* newHarvest = new Cherry(getRand(0.1, 0.3), "red");
		_remainingHarvest--;
		return newHarvest;
	}

	size_t getRemainingHarvest() override { return _remainingHarvest; }
	std::string getName() override { return _currentCultureClassName; }
	std::string getName() const override { return _currentCultureClassName; }


	int getSize() override { return int(_size); }
	std::string getColor() override { return int(_color); }
	int getMaxHarvest() override { return _maxHarvest; }

};