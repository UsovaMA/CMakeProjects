#include <iostream>
#include <Windows.h>

#include "functions.h"


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Parser exp;
	std::cin >> exp;
	system("cls");
	std::cout << exp;
	exp.DeleteSpaces();
	std::cout << exp;
	if (exp.CheckBracket() == 1) {
		std::cout << "м€у";
	}
	else {
		std::cout << "не м€у";
	}


	//bool flag = 0;
	//while (1) {
	//	int menu_choice = 0;
	//	PrintMenu();
	//	std::cin >> menu_choice;
	//	switch (menu_choice) {
	//	case 1:
	//	case 2:
	//		return 0;
	//	}
	//}
	system("pause");
	return 0;
}
