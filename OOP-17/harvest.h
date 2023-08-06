#pragma once
#include <iostream>
#include <string>
#include <vector>

class Harvest {
private:
	std::string _name;
	std::string _color;
	double _weight;
public:
	Harvest();
	Harvest(std::string name, std::string color, double weight);
	std::string getName();
	std::string getColor();
	double getWeight();
	virtual ~Harvest();
	virtual void printInfo();
	/*virtual Harvest* getHarvest() = 0;   |
	virtual size_t getHarvestRemain() = 0; | <--Если раскомментировать,то появятся новые ошибки*/
};