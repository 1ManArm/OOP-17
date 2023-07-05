#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "harvest.h"


class Culture {
private:
	std::string _name;
	std::string _size;
	std::string _color;
	int _harvQuant;
public:
	Culture();
	Culture(const std::string name, const std::string size, const std::string color);
	std::string getName()const;
	std::string getSize()const;
	std::string getColor()const;
	virtual ~Culture();
	virtual void printInfo()const;
	virtual Harvest* harvestType() = 0;
};