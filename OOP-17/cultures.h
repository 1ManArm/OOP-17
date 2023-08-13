#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "harvest.h"
#include "BaseCulture.h"


class Culture : public baseHarvest {
protected:
	enum cultureSize { small, medium, large } _size;
	size_t _maxHarvest;
	std::string _color;
	int _harvQuant;
public:
	enum class cultureType{CherryTree, _endOfEnum};
	Culture();
	/*Culture(const std::string name, const std::string size, const std::string color);*/
	Culture(size_t size, std::string color, size_t maxHarvest) :_size(cultureSize(_size)), _color(_color), _maxHarvest(_maxHarvest){}

	/*std::string getName()const;*/
	/*std::string getSize()const;*/
	std::string getColor()const;
	virtual ~Culture();
	virtual void printInfo()const;
	virtual Harvest* harvestType() = 0;

	int getSize() override = 0;
	std::string getColor() override { return _color; }
	int getMaxHarvest() override { return _maxHarvest; }

	virtual void info() {
		std::cout << "Размер " << _size;
		std::cout << "Цвет " << _color;
		std::cout << "Урожай " << _maxHarvest;
	}

	virtual void info() const {
		std::cout << "Размер " << _size;
		std::cout << "Цвет " << _color;
	}

	Harvest* getHarvest() override = 0;
	
	virtual size_t getHarvestRemain() = 0;
	virtual std::string getName() = 0;
	virtual std::string getName() const = 0;

	friend std::ostream& operator << (std::ostream& out, const Culture& Culture_obj) {
		out << "Размер " << Culture_obj._size;
		out << "Цвет " << Culture_obj._color;
		out << "Урожай " << Culture_obj._maxHarvest;
	}
};