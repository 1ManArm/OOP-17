#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <algorithm>
#include <conio.h>
#include <windows.h>
#include "cultures.h"
#include "harvest.h"
#include "CherryTree.h"
#include "backpack.h"
#include "Menu.h"
#include "Location.h"
#include "ServiceFunctions.h"
//Наследование
/*
class
	поля   |						|Наследование функционала
		   |public private protected|
	методы |						|Реализация

	3 типа наследования:
		public - у родителя публичный, у наследника приватный
		private 
		protected 
		virtual

	2 кодовых слова: virtual и override

	1. Совпадение названия
	2. Полное совпадение аргументов
	3. В базовом классе этот метод помечен как virtual
*/

//class Base {
//public:
//	int publicMember;
//	Base() {
//		std::cout << this << " Создан базовый объект\n";
//	}
//
//	Base(int a, int b, int c) : publicMember(a), protectedMember(b), privateMember(c) {
//		std::cout << this << " Создан базовый объект\n";
//	}
//
//	virtual ~Base() {
//		std::cout << this << " Удален базовый объект\n";
//	}
//
//	virtual int Bar(int a, bool b) = 0;
//	//чистая виртуальная функция не имеет реализации, превращает класс в абстрактный, все наследники, которые не имеют своей реализации тоже становятся абстрактными
//	
//	//абстрактный класс содержит одну и более чистых виртуальных функций и не может иметь собственных объектов
//	//единственный способ создания данных типа interface
//
//private:
//	int privateMember;
//protected:
//	int protectedMember;
//};

//class Derived : public Base {
//	void bar() {
//		this->protectedMember;
//		this->publicMember;
//	}
//	//publicMember - остается публичным
//	//privateMember - недоступен
//	//protectedMember - становится защищенным
//	int selfState;
//public:
//	Derived():Base() {
//		std::cout << this << " Создан разветвленный объект\n";
//	}
//	Derived(int a, int b, int c):Base(a, b, c) {
//		std::cout << this << " Создан разветвленный объект\n";
//	}
//	~Derived() override {
//		std::cout << this << " Удален разветвленный объект\n";
//	}
//	int Bar(int a, bool b) override {
//		return a | b;
//	}
//};
//
//class Derived2 : protected Base {
//	//publicMember - становится защищенным
//	//protectedMember - становится защищенным
//	//privateMember - недоступен
//
//public:
//	Derived2() {
//		std::cout << this << " Создан разветвленный объект 2\n";
//	}
//	~Derived2() {
//		std::cout << this << " Удален разветвленный объект 2\n";
//	}
//	int Bar(int a, bool b) override {
//		return a | b;
//	}
//	int pole;
//	
//};
//
//class Derived3 : private Base {
//	//publicMember - становится приватным
//	//protectedMember - становится приватным
//	//privateMember - недоступен
//public:
//	Derived3() {
//		std::cout << this << " Создан разветвленный объект 3\n";
//	}
//	~Derived3() {
//		std::cout << this << " Удален разветвленный объект 3\n";
//	}
//	int Bar(int a, bool b) override {
//		return a | b;
//	}
//};

void task1(std::string taskName)
{
	do
	{
		system("cls");
		std::cout << "***\t" << taskName << "\n";

		CultureLocation Location1(3);
		BackPack main_back_pack;

		std::cout << "\nLocation1.Info()";
		Location1.Info();


		std::cout << "\n\n\n// Player interface\n";
		locationPlayerInterface* locationPlayerInterface_ptr = &Location1;

		std::cout << "\nshowPlants()";
		locationPlayerInterface_ptr->showPlants();
		locationPlayerInterface_ptr->getHarvest(0, &main_back_pack);
		std::cout << "\n\nAfter harvesting Plant 1 -> showPlants()";
		locationPlayerInterface_ptr->showPlants();


		std::cout << "\n\n\n// TheGame interface\n";
		locationGameInterface* locationGameInterface_ptr = &Location1;

		std::cout << "\nAddNewPlant() -> Info()";
		locationGameInterface_ptr->AddNewPlant();
		Location1.Info();
		std::cout << "\n\nDeletePlant() -> DeletePlant() -> Info()";
		locationGameInterface_ptr->DeletePlant();
		locationGameInterface_ptr->DeletePlant();
		Location1.Info();


		std::cout << "\n\nEsc - exit | any key to continue";
	} while (_getch() != 27);
}

void task2(std::string taskName)

{
	do
	{
		system("cls");
		std::cout << "***\t" << taskName << "\n";

		BackPack mainBackpack;
		CultureLocation Location2(5);

		std::cout << "\n\n\n// Player interface\n";
		backpackPlayerInterface* backpackPlayerInterface_ptr = &mainBackpack;

		std::cout << "\nEmpty Backpack -> Info()\n";
		backpackPlayerInterface_ptr->info();

		std::cout << "\n\nLocation2.showPlants()";
		Location2.showPlants();

		std::cout << "\n\n\nBackpack after harvesting Plants 1, 2 and 3 -> Info()";

		backpackPlayerInterface_ptr->addItem(*Location2[0].getName());
		backpackPlayerInterface_ptr->addItem(*Location2[1].getName());
		backpackPlayerInterface_ptr->addItem(*Location2[2].getName());
		backpackPlayerInterface_ptr->info();

		std::cout << "\n\n\nBackPack after deleting 1 item -> Info()";
		backpackPlayerInterface_ptr->deleteItem();
		backpackPlayerInterface_ptr->info();
		
		std::cout << "\n\n\n// Game interface\nInfo() method only";
		backpackPlayerInterface* backpackPlayerInterface_ptr = &mainBackpack;

		backpackPlayerInterface_ptr->info();

		std::cout << "\n\nEsc - exit | any key to continue";
	} while (_getch() != 27);
}

void task3() {}

void task4() {}

int main() {
	setlocale(LC_ALL, "Russian");

	/*Base obj(2, 5, 7);
	obj.publicMember;*/

	/*Derived objDer(2, 5, 6);
	obj.publicMember;

	Derived2 objDer2;
	objDer2.pole;*/

	/*Derived3 objDer3;

	Base* obj;
	int* p_int = new int{ 6 };
	obj = new Derived{2,5,6};
	delete obj;*/

	//Culture* newcult = new CherryTree(/*"Cherry",*/ "large", "red", 56.3);
	//newcult->printInfo();
	//std::cout << std::endl;

	//Harvest* newharvest = newcult->harvestType();
	//newharvest->printInfo();

	//delete newharvest;

	//std::vector<std::unique_ptr<Culture>> location;
	//location.emplace_back(std::make_unique<CherryTree>("", "", 4));

	srand(time(NULL));
	mainMenu startMenu;
	startMenu.addElem("OOP Home Work 13: Interfaces");
	startMenu.addElem("Location class demo through different interfaces:\nInterface 1: Player\nInterface 2: Game\n");
	startMenu.addElem("BackPack class demo through different interfaces:\nInterface 1: Player\nInterface 2: Game");

	do
	{
		startMenu.showMenu();
		if (!startMenu.userChoiceHandle(_getch()))	break;
	} while (true);

	return 0;
}