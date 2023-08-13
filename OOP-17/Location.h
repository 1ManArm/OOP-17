#pragma once
#include <vector>
#include "ServiceFunctions.h"
#include "CherryTree.h"
#include "harvest.h"
#include "backpack.h"
#include "cultures.h"

class locationPlayerInterface
{
public:
	virtual ~locationPlayerInterface() {}; 
	virtual void showPlants() = 0;
	virtual void getHarvest(int plantIndex, backpackPlayerInterface* backpack) = 0;
};

class locationGameInterface
{
public:
	virtual ~locationGameInterface() {}; 
	virtual Culture* addNewPlant() = 0;
	virtual void deletePlant() = 0;
};

class CultureLocation : virtual public locationGameInterface, virtual public locationPlayerInterface {
	std::vector<Culture*> _plantsList;
	int const culturesMinRand = 30;
	int const culturesMaxRand = 100;
public:
	CultureLocation(int plantsNumber)
	{
		Culture* newPlant = nullptr;
		for (int i = 0; i < plantsNumber; i++)
		{
			newPlant = getRandPlant();
			_plantsList.push_back(newPlant);
		}
	}
	CultureLocation() {
		int culturesNum = getRand(culturesMinRand, culturesMaxRand);
		for (int i = 0; i < culturesNum; i++) {
			_plantsList.push_back(getRandPlant());
		}
	}
	~CultureLocation()
	{
		for (int i = 0; i < _plantsList.size(); i++)
			delete _plantsList[i];
		_plantsList.clear();
	}

	Culture* addNewPlant() override
	{
		Culture* newCult = getRandPlant();
		_plantsList.push_back(newCult);
		return newCult;
	}
	Culture* getRandPlant() {
		Culture* newCult = nullptr;
		int size = getRand(0, 3);
		color parameter = static_cast<color>(getRand(0, int(color::_endOfEnum)));
		size_t maxHarvest = getRand(20 * (size + 1), 50 * (size + 1));
		int randCultChoice = getRand(0, int(Culture::cultureType::_endOfEnum));
		switch (randCultChoice) {
		case 0: newCult = new CherryTree(size, parameter, maxHarvest);
		}
		return newCult;

	}
	void deletePlant() override
	{
		_plantsList.pop_back();
	}
	void showPlants() override
	{
		for (int i = 0; i < _plantsList.size(); i++)
		{
			std::cout << "\nTree " << i + 1;
			std::cout << " " << _plantsList[i]->getName();
			std::cout << " Fruits remain: " << _plantsList[i]->harvestType();
		}
	}
	void getHarvest(int tree_index, backpackPlayerInterface* back_pack) override
	{
		if (tree_index <= _plantsList.size() && tree_index >= 0)
			back_pack->addItem(*_plantsList[tree_index]->harvestType());
	}


	void Info()
	{
		for (int i = 0; i < _plantsList.size(); i++)
		{
			std::cout << "\n\nTree " << i + 1;
			_plantsList[i]->printInfo();
		}
	}

	void InfoEx() {
		std::map <std::string, int> ingroupCount;
		std::map <std::string, double> ingroupHarvest;

		double totalHarvest = 0;

		for (int i = 0; i < _plantsList.size(); ++i) {
			++ingroupCount[_plantsList[i]->getName()];
			ingroupHarvest[_plantsList[i] - getName()] += _plantsList[i]->getRemainHarv;
			totalHarvest += _plantsList[i]->getRemainHarv;
		}
		for (auto iter = ingroupCount.begin(); iter != ingroupCount.end(); iter++) {
			std::cout << "\n" << iter->first << ": " << iter->second << "\tHarvest: " << ingroupHarvest[iter->first];
		}
		std::cout << "\n\nВсего культур " << _plantsList.size();
		std::cout << "\nВсего плодов " << totalHarvest << "\n\n";
	}
	class iterator
	{
		Culture** _dataIterator;

	public:
		iterator() = delete;
		iterator(Culture** data) : _dataIterator(data) {}

		iterator& operator++()
		{
			_dataIterator++;
			return *this;
		}

		iterator& operator++(int)
		{
			iterator tmp(*this);
			_dataIterator++;
			return tmp;
		}

		iterator& operator--()
		{
			_dataIterator--;
			return *this;
		}

		iterator& operator--(int)
		{
			iterator tmp(*this);
			_dataIterator--;
			return tmp;
		}

		Culture& operator*()
		{
			return **_dataIterator;
		}
		bool operator != (const iterator& obj)
		{
			return (this->_dataIterator != obj._dataIterator);
		}
		bool operator == (const iterator& obj)
		{
			return this->_dataIterator == obj._dataIterator;
		}

	};

	iterator begin() { return &_plantsList[0]; }
	iterator end() { return &_plantsList[_plantsList.size() - 1]; }
	
	Culture& operator [ ] (int index) { return *_plantsList[index]; }
	auto at(size_t index) const -> const Culture& {
		return *_plantsList.at(index);
	}
};