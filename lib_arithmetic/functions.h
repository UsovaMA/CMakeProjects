// Copyright 2023 Mezhuev Maksim
#ifndef FUNCTIONS_FUNCTIONS_H_
#define FUNCTIONS_FUNCTIONS_H_

#include <algorithm>
#include <stdexcept>
#include <cstdlib>
#include <string>
#include <iostream>
#include <Windows.h>
#include "../lib_stack/stack.h"
#include "../lib_list/list.h"


void PrintMenu(const std::string expression) {
	std::cout << "Ваше выражение: " << expression << std::endl;
	std::cout << "Меню:" << std::endl;
	std::cout << "  1. Задать значение переменной." << std::endl;
	std::cout << "  2. Увидеть обратную польскую записсь." << std::endl;
	std::cout << "  3. Вычислить значение функции." << std::endl;
	std::cout << "  4. Вернуться к заданию выражения." << std::endl;
	std::cout << "  5. Выход." << std::endl;
	std::cout << "Выбор: ";
}


struct variable {
    std::string name;
    double value;
};

class Parser {
    friend class Stack<std::string>;
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

    bool CheckBracket() {
        Stack<std::string> stack(15);
        for (int i = 0; i < expression.size(); i++) {
            if (expression[i] == '(') {
                stack.push(std::to_string(expression[i]));
            }
            if (expression[i] == '{') {
                stack.push(std::to_string(expression[i]));
            }
            if (expression[i] == '[') {
                stack.push(std::to_string(expression[i]));
            }
            if (expression[i] == ')') {
                if (stack.getTop() == std::to_string('(')) {
                    stack.pop();
                }
                else {
                    return 0;
                }
            }
            if (expression[i] == ']') {
                if (stack.getTop() == std::to_string('[')) {
                    stack.pop();
                }
                else {
                    return 0;
                }
            }
            if (expression[i] == '}') {
                if (stack.getTop() == std::to_string('{')) {
                    stack.pop();
                }
                else {
                    return 0;
                }
            }

        }
        if ((stack.isEmpty() == true)) {
            return 1;
        }
        else {
            return 0;
        }
    }

    int CheckSyntax() {
        std::string nums = "0123456789";
        std::string lett = "qwertyuiopasdfghjklzxcvbnm";
        std::string lettnum = nums + lett;
        std::string arith = "+-/*^";
        std::string brackets = "()[]{}";
        std::string state2 = lettnum + brackets;
        int state = 0;
        int k = 0;
        char s;
        int i = 0;
        for (int i = 0; i < expression.length(); i++) {
            switch (state) {
            case 0:
                if (i == expression.length() - 1) {
                    state = 2;
                }
                else if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
                    k = k + 1;
                    continue;
                }
                else if (lettnum.find(expression[i]) != std::string::npos) {
                    state = 1;
                    continue;
                }
                else {
                    throw;
                }
            case 1:
                if (i == expression.length() - 1) {
                    state = 2;
                }
                else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}') {
                    k = k - 1;
                    if (k >= 0) {
                        state = 1;
                        continue;
                    }
                    else {
                        throw;
                    }
                }
                else if (arith.find(expression[i]) != std::string::npos) {
                    state = 0;
                    continue;
                }
                else {
                    throw;
                }
            case 2:
                if (state2.find(expression[i]) != std::string::npos) {
                    if (k == 1) {
                        return 0;
                    }
                    else {
                        throw;
                    }
                }
                else {
                    throw;
                }
            }

        }
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

class Expression {
    std::string expression;
    std::string poland;
    variable* var;
};

#endif FUNCTIONS_FUNCTIONS_H_