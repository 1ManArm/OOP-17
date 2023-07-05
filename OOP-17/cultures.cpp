#include "cultures.h"
#include "harvest.h"

Culture::Culture(){}

Culture::Culture(const std::string name, const std::string size, const std::string color): _name(name), _size(size), _color(color){}

std::string Culture::getName()const{
	return _name;
}

std::string Culture::getSize()const{
	return _size;
}

std::string Culture::getColor()const{
	return _color;
}

void Culture::printInfo()const{
	std::cout << "Имя: " << Culture::getName() << '\n';
	std::cout << "Размер: " << Culture::getSize() << '\n';
	std::cout << "Цвет: " << Culture::getColor() << '\n';
}

Culture::~Culture(){
	std::cout << " Данные удалены" << std::endl;
}
