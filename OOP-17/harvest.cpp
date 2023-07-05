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
	std::cout << "Имя: " << Harvest::getName() << '\n';
	std::cout << "Цвет: " << Harvest::getColor() << '\n';
	std::cout << "Вес: " << Harvest::getWeight() << '\n';
}

Harvest::~Harvest(){
	std::cout << " Данные удалены\n";
}

#endif