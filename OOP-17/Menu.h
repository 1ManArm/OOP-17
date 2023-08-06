#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "ServiceFunctions.h"
#include <windows.h>

extern void task1(std::string);
extern void task2(std::string);
extern void task3();
extern void task4();

class mainMenu {
	std::vector<std::string>_menuElems;
public:
	void addElem(std::string menuElem) { _menuElems.push_back(menuElem); }
	void showMenu();
	int userChoiceHandle();
	int userChoiceHandle(int keyCode);
};