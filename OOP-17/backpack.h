#pragma once
#include "harvest.h"
#include <memory>
#include <cassert>

class backpackPlayerInterface {
public:
	virtual ~backpackPlayerInterface() = default;
	virtual void addItem(Harvest& newHarvest) = 0;
	virtual void deleteItem() = 0;
	virtual void info() = 0;
	virtual void operator << (const Harvest& newHarvest) = 0;
	virtual void operator << (Harvest& newHarvest) = 0;
};

class backpackGameInterface {
public:
	virtual ~backpackGameInterface() = default;
	virtual void info() = 0;
};

class BackPack : virtual public backpackPlayerInterface, virtual public backpackGameInterface
{
	/*std::vector<std::unique_ptr<Harvest>> _itemList;*/
	std::vector<Harvest*> _itemList;

	void deleteItem(std::string type) {
		for (int i = 0; i < _itemList.size(); ++i) {
			if (_itemList[i]->getName() == type) {
				delete _itemList[i];
				_itemList.erase(_itemList.begin() + i);
				--i;
			}
		}
	}

public:

	BackPack() {};

	void addItem(Harvest& newHarvest) override
	{
		if (newHarvest) _itemList.push_back(newHarvest);
	}

	void deleteItem(size_t index) override
	{
		if (index < 0 || index >= _itemList.size()) assert(true && "Deleting index out of range");
		delete _itemList[index];
		_itemList.erase(_itemList.begin() + index);
	}

	void deleteItem(size_t beginIndex, size_t endIndex) {
		if(beginIndex < 0 || beginIndex >= _itemList.size()) assert(true && "Deleting index out of range");
		if (endIndex < 0 || endIndex >= _itemList.size()) assert(true && "Deleting index out of range");
		if (beginIndex > endIndex) std::swap(beginIndex, endIndex);

		for (int i = beginIndex; i < endIndex; ++i)
			delete _itemList[i];
		_itemList.erase(_itemList.begin() + beginIndex, _itemList.begin() + endIndex);
	}

	void deleteItem(Harvest::harvestType type) {
		switch (type) {
		case Harvest::harvestType::Cherry:
			deleteItem("Cherry"); break;
		}
	}

	void info() override
	{
		if (_itemList.size() == 0)
		{
			std::cout << "No items";
			return;
		}
		for (int i = 0; i < _itemList.size(); i++)
		{
			std::cout << "\n\nItem " << i + 1;
			_itemList[i]->printInfo();
		}
	}

	void ShortInfo()
	{
		std::map <std::string, int> ingroupCount;
		std::map <std::string, double> ingroupWeight;

		double totalWeight = 0;
		for (int i = 0; i < _itemList.size(); ++i)
		{
			++ingroupCount[_itemList[i]->getName()];
			ingroupWeight[_itemList[i]->getName()] += _itemList[i]->getWeight();
			totalWeight += _itemList[i]->getWeight();
		}
			
		for (auto iter = ingroupCount.begin(); iter != ingroupCount.end(); iter++)
		{
			std::cout << iter->first << ": " << iter->second << "\t Weight: " << ingroupWeight[iter->first] << " kg\n";
		}
		std::cout << "\nTotal items  " << _itemList.size();
		std::cout << "\nTotal weight " << totalWeight << " kg";

	}

	void operator << (const Harvest& newHarvest) override
	{
		assert(true);
	}
	void operator << (Harvest& newHarvest)
	{
		addItem(&newHarvest);
	}
	Harvest* operator [] (int index)
	{
		if (index < 0 || index >= _itemList.size()) assert(true && "Index out of range");
		return _itemList[index];
	}
	size_t size() { return _itemList.size(); }
	auto at(size_t index) const -> Harvest&
	{
		return *_itemList.at(index);
	}

	class iterator
	{
		Harvest** _dataIterator; 

	public:
		iterator() = delete;
		iterator(Harvest** data) : _dataIterator(data) {}

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

		Harvest& operator*()
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
	iterator begin() { return &_itemList[0]; }
	iterator end() { return &_itemList[0] + _itemList.size(); }

};