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
	std::vector<std::unique_ptr<Harvest>> _itemList;

public:

	BackPack() {};

	void addItem(Harvest& newHarvest) override
	{
		std::unique_ptr<Harvest> p_uniq = std::make_unique<Harvest>(std::move(newHarvest));

		_itemList.push_back(std::move(p_uniq));
	}

	void deleteItem() override
	{
		_itemList.pop_back();
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

	void operator << (const Harvest& newHarvest) override
	{
		assert(true);
	}
	void operator << (Harvest& newHarvest)
	{
		_itemList.push_back(std::make_unique<Harvest>(std::move(newHarvest)));
	}

};