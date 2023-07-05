#include <iostream>
#include <string>
#include <vector>
#include "cultures.h"
#include "harvest.h"
#include "CherryTree.h"
//������������
/*
class
	����   |						|������������ �����������
		   |public private protected|
	������ |						|����������

	3 ���� ������������:
		public - � �������� ���������, � ���������� ���������
		private 
		protected 
		virtual

	2 ������� �����: virtual � override

	1. ���������� ��������
	2. ������ ���������� ����������
	3. � ������� ������ ���� ����� ������� ��� virtual
*/

//class Base {
//public:
//	int publicMember;
//	Base() {
//		std::cout << this << " ������ ������� ������\n";
//	}
//
//	Base(int a, int b, int c) : publicMember(a), protectedMember(b), privateMember(c) {
//		std::cout << this << " ������ ������� ������\n";
//	}
//
//	virtual ~Base() {
//		std::cout << this << " ������ ������� ������\n";
//	}
//
//	virtual int Bar(int a, bool b) = 0;
//	//������ ����������� ������� �� ����� ����������, ���������� ����� � �����������, ��� ����������, ������� �� ����� ����� ���������� ���� ���������� ������������
//	
//	//����������� ����� �������� ���� � ����� ������ ����������� ������� � �� ����� ����� ����������� ��������
//	//������������ ������ �������� ������ ���� interface
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
//	//publicMember - �������� ���������
//	//privateMember - ����������
//	//protectedMember - ���������� ����������
//	int selfState;
//public:
//	Derived():Base() {
//		std::cout << this << " ������ ������������� ������\n";
//	}
//	Derived(int a, int b, int c):Base(a, b, c) {
//		std::cout << this << " ������ ������������� ������\n";
//	}
//	~Derived() override {
//		std::cout << this << " ������ ������������� ������\n";
//	}
//	int Bar(int a, bool b) override {
//		return a | b;
//	}
//};
//
//class Derived2 : protected Base {
//	//publicMember - ���������� ����������
//	//protectedMember - ���������� ����������
//	//privateMember - ����������
//
//public:
//	Derived2() {
//		std::cout << this << " ������ ������������� ������ 2\n";
//	}
//	~Derived2() {
//		std::cout << this << " ������ ������������� ������ 2\n";
//	}
//	int Bar(int a, bool b) override {
//		return a | b;
//	}
//	int pole;
//	
//};
//
//class Derived3 : private Base {
//	//publicMember - ���������� ���������
//	//protectedMember - ���������� ���������
//	//privateMember - ����������
//public:
//	Derived3() {
//		std::cout << this << " ������ ������������� ������ 3\n";
//	}
//	~Derived3() {
//		std::cout << this << " ������ ������������� ������ 3\n";
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