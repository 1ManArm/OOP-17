#include <iostream>
#include <string>
#include <vector>
#include "cultures.h"
#include "harvest.h"
#include "CherryTree.h"
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

	Culture* newcult = new CherryTree("Cherry", "large", "red", 56.3);
	newcult->printInfo();
	std::cout << std::endl;

	Harvest* newharvest = newcult->harvestType();
	newharvest->printInfo();

	delete newharvest;

	return 0;
}