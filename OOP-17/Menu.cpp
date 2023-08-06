#include "Menu.h"

void mainMenu::showMenu()
{
	system("cls");
	std::cout << "\n\t***\t" << _menuElems[0] << "\t***\n\n\t\n\nChoose an option: \n";	
	for (int i = 1; i < _menuElems.size(); i++)
		std::cout << "\n" << i << ". " << _menuElems[i];
	std::cout << "\n\n 0. Exit\n";
	std::cout << "\nYour choice: ";
}

int mainMenu::userChoiceHandle()
{
	int choice = 0;
	choice = getIntPos();
	std::cout << "\n";
	if (choice == 0) { std::cout << "\nGood Bye"; for (int j = 0; j < 50; j++) { Sleep(50 - j); std::cout << "y"; } std::cout << "e!"; Sleep(850);  return 0; }

	else if (choice == 1) task1(_menuElems[1]);
	else if (choice == 2) task2(_menuElems[2]);
	else if (choice == 3) task3();
	else if (choice == 4) task4();

	else { std::cout << "\nNonexistent option was selected\n"; Sleep(1000); }
	return 1;
}

int mainMenu::userChoiceHandle(int keyCode)
{
	std::cout << keyCode - 48 << "\n\n";
	switch (keyCode)
	{
	case 27: case 48:
	{ std::cout << "\nGood Bye"; for (int j = 0; j < 50; j++) { Sleep(50 - j); std::cout << "y"; } std::cout << "e!"; Sleep(850);  return 0;	}
	case 49: task1(_menuElems[1]); break;
	case 50: task2(_menuElems[2]); break;
	case 51: task3(); break;
	case 52: task4(); break;
	
	default: { std::cout << "\nNonexistent option was selected\n"; Sleep(1000); }
	}
	return 1;
}
