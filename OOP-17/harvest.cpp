#ifndef HARVEST_H
#define HARVEST_H


#include "harvest.h"
#include "cultures.h"

Harvest::Harvest() {}

Harvest::Harvest(std::string name, std::string color, double weight) : _name(name), _color(color), _weight(weight) {}

std::string Harvest::getName() {
	return _name;
}

std::string Harvest::getColor() {
	return _color;
}

double Harvest::getWeight() {
	return _weight;
}

void Harvest::printInfo(){
	std::cout << "���: " << Harvest::getName() << '\n';
	std::cout << "����: " << Harvest::getColor() << '\n';
	std::cout << "���: " << Harvest::getWeight() << '\n';
}

Harvest::~Harvest(){
	std::cout << " ������ �������\n";
}

#endif