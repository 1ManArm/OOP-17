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
	virtual Culture* AddNewPlant() = 0;
	virtual void DeletePlant() = 0;
};

class CultureLocation : virtual public locationGameInterface, virtual public locationPlayerInterface {
	std::vector<Culture*> _plantsList;
public:
	CultureLocation(int plantsNumber)
	{
		Culture* newPlant = nullptr;
		for (int i = 0; i < plantsNumber; i++)
		{
			int size = getRand(0, 3);
			std::string color parameter = static_cast<color>(getRand(0, 6));
			double maxHarvest = getRand(50 * (size + 1), 150 * (size + 1));
			if (getRand(0, 2)) { newPlant = new CherryTree(size, color, maxHarvest); }
			_plantsList.push_back(newPlant);
		}
	}
	~CultureLocation()
	{
		for (int i = 0; i < _plantsList.size(); i++)
			delete _plantsList[i];
		_plantsList.clear();
	}

	Culture* AddNewPlant() override
	{
		Culture* newCult = nullptr;
		if (getRand(0, 2)) { newCult = new CherryTree(size, color, maxHarvest); }
		_plantsList.push_back(newCult);
		return newCult;
	}
	void DeletePlant() override
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
	class iterator
	{
		Culture* _dataIterator;

	public:
		iterator() = delete;
		iterator(Culture* data) : _dataIterator(data) {}

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
			return *_dataIterator;
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

	Culture& operator [ ] (int index) { return *_plantsList[index]; }
	iterator begin() { return _plantsList[0]; }
	iterator end() { return _plantsList[_plantsList.size() - 1]; }
};