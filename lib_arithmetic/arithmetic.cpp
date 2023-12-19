#include <iostream>
#include <Windows.h>

#include "functions.h"
#include "MathFunc.h"


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int x = 0;

	Parser p;
	std::cin >> p;
	p.DeleteSpaces();
	p.CheckSyntax();
	p.CheckFunc();

	std::cout << p.CheckSyntax();
	std::cout << p.CheckFunc();
	system("pause");
	return 0;
}
