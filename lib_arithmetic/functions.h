// Copyright 2023 Mezhuev Maksim
#ifndef FUNCTIONS_FUNCTIONS_H_
#define FUNCTIONS_FUNCTIONS_H_


#include <cstdlib>
#include <string>
#include <iostream>
#include <Windows.h>

void PrintMenu() {
	//std::cout << "Ваше выражение: " << expression << std::endl;
	std::cout << "Меню:" << std::endl;
	std::cout << "  1. Задать значение переменной." << std::endl;
	std::cout << "  2. Увидеть обратную польскую записсь." << std::endl;
	std::cout << "  3. Вычислить значение функции." << std::endl;
	std::cout << "  4. Вернуться к заданию выражения." << std::endl;
	std::cout << "  5. Выход." << std::endl;
	std::cout << "Выбор: ";
}



class Parser {
	std::string expression;
public:
	Parser() {
		expression = "none";
	}
	Parser(std::string _expression) : expression(_expression) {}
	Parser(const Parser& p) :expression(p.expression) {}

	std::string get_expression() const {
		return expression;
	}

	friend std::ostream& operator << (std::ostream& out, const Parser& p);
	friend std::istream& operator>>(std::istream& input, Parser& p);


	void DeleteSpaces() {
		expression.erase(remove(expression.begin(), expression.end(), ' '), expression.end());
	}
};


std::istream& operator>>(std::istream& input, Parser& p) {
	std::cout << "Введите выражение: ";
	getline(input, p.expression);
	return input;
}

std::ostream& operator<<(std::ostream& out, Parser& p) {
	out << "Ваше выражение: " << p.get_expression() << std::endl;
	return out;
}


#endif FUNCTIONS_FUNCTIONS_H_