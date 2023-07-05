#include <iostream>
#include <string>
#include <vector>
#include "CherryTree.h"
#include "Fruit.h"

void CherryTree::printInfo() const {
	Culture::printInfo();
	std::cout << "Кол-во плодов: " << _harvQuant << std::endl;
}

Harvest* CherryTree::harvestType()
{
	--_harvQuant;
	return new Fruit("Cherry", "red", 56.3);
}
