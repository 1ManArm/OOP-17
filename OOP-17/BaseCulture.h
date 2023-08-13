#pragma once
#include "harvest.h"

class baseHarvest {
public:
	virtual ~baseHarvest() = default;
	virtual int getSize() = 0;
	virtual std::string getColor() = 0;
	virtual int getMaxHarvest() = 0;
	virtual Harvest* getHarvest() = 0;
};