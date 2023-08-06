#ifndef _ServiceFunctions_h_
#define _ServiceFunctions_h_
#include <iostream>
#include <string>

int getIntSA();
int getIntPos();
int getIntPos(int bottomLim, int upLim, std::string comment);
int getIntPG();
double getDblSA();
double getDblPos();
double getDblPG();
int getRand(int minRange, int maxRange);
double getRand(double minRange, double maxRange);

template <typename X>
void arrConsoleOut(X arr[], int size) {
	std::cout << "\n[";
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}
template <typename X>
void fillArrWithRand(X arr[], int size, X minRange, X maxRange) {
	for (int i = 0; i < size; i++) {
		arr[i] = getRand(minRange, maxRange);
	}
}
#endif // !_ServiceFunctions_h_

