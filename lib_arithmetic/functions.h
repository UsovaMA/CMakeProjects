// Copyright 2023 Mezhuev Maksim
#ifndef FUNCTIONS_FUNCTIONS_H_
#define FUNCTIONS_FUNCTIONS_H_

#include <algorithm>
#include <stdexcept>
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

template <class T>
class Stack {
    size_t size;
    T* data;
    size_t top;


public:
    Stack() : size(0), data(nullptr), top(-1) { }

    Stack(int size_) {
        size = size_;
        top = -1;
        data = new T[size];
    }
    Stack(const Stack& st) {
        size = st.size;
        top = st.top;
        data = new T[size];
        for (int i = 0; i < size; i += 1) {
            data[i] = st.data[i];
        }
    }
    ~Stack() {
        delete[]data;
        data = nullptr;
    }
    bool isEmpty() {
        return top == -1;
    }
    bool isFull() {
        return size == top + 1;
    }
    T& getTop() {
        return data[top];
    }
    void pop() {
        if (isEmpty()) {
            throw std::logic_error("Stack is empty!");
        }
        top--;
    }
    void push(T elem) {
        if (isFull()) {
            throw std::logic_error("Stack is full!");
        }
        top++;
        data[top] = elem;
    }

    void print() {
        Stack copy(*this);
        while (!copy.isEmpty()) {
            std::cout << copy.getTop() << '\n';
            copy.pop();
        }
    }
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
        int bracket1 = 0;
        int bracket2 = 0;
        int bracket3 = 0;
        for (int i = 0; i < expression.size(); i++) {
            if (expression[i] == '(') {
                stack.push(std::to_string(expression[i]));
                bracket1++;
            }
            if (expression[i] == '{') {
                stack.push(std::to_string(expression[i]));
                bracket2++;
            }
            if (expression[i] == '[') {
                stack.push(std::to_string(expression[i]));
                bracket3++;
            }
            if (expression[i] == ')') {
                stack.pop();
                bracket1--;
            }
            if (expression[i] == '}') {
                stack.pop();
                bracket2--;
            }
            if (expression[i] == ']') {
                stack.pop();
                bracket3--;
            }

        }
        if ((stack.isEmpty() == true) && bracket1 == 0 && bracket2 == 0 && bracket3 == 0) {
            return 1;
        }
        else {
            return 0;
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


#endif FUNCTIONS_FUNCTIONS_H_