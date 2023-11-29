// Copyright 2023 Aleksey Lavrentyev

#ifndef LIB_ALGORITHMS_ALGORITHMS_H
#define LIB_ALGORITHMS_ALGORITHMS_H
//в лексемы добавить перегрузить оператор присваивани€ = , в списке посмотреть конструктор копировани€, доделать тесты
#include <string>
#include "../lib_list/list.h"
#include "../lib_stack_on_list/stackOnList.h"
//extra лишн€€ закрыта€, missing лишн€€ открыта€
enum class TYPE_ERROR {
	EXTRA_BRACKET = 0,
	MISSING_BRACKET = 1,
	MISMATCHED_BRACKET = 2,
	UNVALID_BRACKET = 3,
	NON_ERROR = 4
};

enum TYPE_LEXEM {
	BRACKET,
	VARIABLE,
	OPERATION,
	FUNCTION,
	INT_CONST,
	FLOAT_CONST
};

struct DescriptionError{
	TYPE_ERROR type;
	int pos;
};

class Lexem {
private:
	std::string name;
	float value;
	TYPE_LEXEM type;
public:
	Lexem(std::string _name, TYPE_LEXEM _type, float _value = NULL) : name(_name), value(_value), type(_type){}
	void set_values(std::string _name, TYPE_LEXEM _type, float _value = NULL) {
		name = _name;
		value = _value;
		type = _type;
	}
	float get_value() {
		return value;
	}
	TYPE_LEXEM get_type() {
		return type;
	}
	std::string get_name() {
		return name;
	}
};
//прошлый символ и тд, пересмотреть запись
namespace parser {
	List<Lexem> listlexem(std::string& s) {
		const int num_of_brackets = 6;
		const int num_of_constants = 10;
		const int num_of_operations = 4;
		const int num_of_functions = 6;
		const int num_of_variables = 26;
		char point = '.';
		bool pointb = 0;
		List<Lexem> lexems;
		Lexem tmp("{", BRACKET);
		/// <summary>
		/// 0-5 скобки
		/// 6-15 константы
		/// 16-19 операции
		/// 20-45 переменные
		/// </summary>
	//	std::char mass[] = { "{", "}", "(", ")", "[", "]", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "+", "-", "*", "/", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z" };
		char mass[] = { "{}()[]0123456789+-*/abcdefghijklmnopqrstuvwxyz" };
		std::string const1 = "";
		/*
							if (const1.size() != 0 && !point) {
						tmp.set_values("constantaint", INT_CONST, std::stoi(const1));
						lexems.push_back(tmp);
						const1 = "";
					}
					if (const1.size() != 0 && point)
						for (int a = 0; a < 6; a++) {
							if (s[i] == mass[a]) {
								char ch = s[i];
								tmp.set_values("constantafloat", INT_CONST, std::stof(const1));
								lexems.push_back(tmp);
								const1 = "";
							}
						}*/

		//std::string valid_brackets[num_of_brackets] = {"{", "}", "(", ")", "[", "]"  };
	//	std::string operations[num_of_operations] = { "+", "-", "*", "/" };
	//	std::string functions[num_of_functions] = { "sin", "cos", "tg", "ctg", "lg", "exp" };
	//	std::string variables[num_of_variables] = { "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z" };
		for (int i = 0; i < s.size(); i++) {
			//скобки
			for (int a = 0; a < 6; a++) {
				if (s[i] == mass[a]) {
					char ch = s[i];
					tmp.set_values(std::to_string(ch), BRACKET);
					lexems.push_back(tmp);
				}
			}
			//числааааааа
			for (int a = 6; a < 16; a++) {
				if (s[i] == mass[a]) {
					const1 += std::to_string(s[i]);
					if (s[i + 1] == point) {
						const1 += point;
						pointb = 1;
					}					
					if (std::isspace(s[i + 1])) {
						if (pointb) {
							tmp.set_values("floatconst", FLOAT_CONST, std::stof(const1));
							lexems.push_back(tmp);
						}
						else {
							tmp.set_values("intconst", INT_CONST, std::stoi(const1));
							lexems.push_back(tmp);
						}
						pointb = 0;
					}
				}
			}
			//операции
			for (int a = 16; a < 20; a++) {
				if (s[i] == mass[a]) {
					char ch = s[i];
					tmp.set_values(std::to_string(ch), OPERATION);
					lexems.push_back(tmp);
					continue;
				}
			}
			//variables
			for (int a = 20; a < 46; a++) {
				if (s[i] == mass[a] && std::isspace(s[i+1]) && isspace(s[i - 1])) {
					char ch = s[i];
					tmp.set_values(std::to_string(ch), VARIABLE);
					lexems.push_back(tmp);
				}	
			}
			//functions
			for (int a = 20; a < 46; a++) {
				if (s[i] == mass[38] && !std::isspace(s[i + 1])) {
					tmp.set_values("sin", FUNCTION);
					lexems.push_back(tmp);
				}
				else if (s[i] == mass[22] && s[i+1] == mass[34]) {
					tmp.set_values("cos", FUNCTION);
					lexems.push_back(tmp);
				}
				else if (s[i] == mass[39] && !std::isspace(s[i + 1])) {
					tmp.set_values("tg", FUNCTION);
					lexems.push_back(tmp);
				}
				else if (s[i] == mass[22] && s[i + 1] == mass[39]) {
					tmp.set_values("ctg", FUNCTION);
					lexems.push_back(tmp);
				}
				else if (s[i] == mass[31] && !std::isspace(s[i + 1])) {
					tmp.set_values("lg", FUNCTION);
					lexems.push_back(tmp);
				}
				else if (s[i] == mass[24] && !std::isspace(s[i + 1])) {
					tmp.set_values("exp", FUNCTION);
					lexems.push_back(tmp);
				}
			}
		}

		return lexems;
	}
	DescriptionError check_brackets(const List<Lexem>& _lexems) {
		StackOnList<std::string> brackets;
		const int num_of_valid_brackets = 6;
		std::string valid_brackets[num_of_valid_brackets] = { "{", "}", "(", ")", "[", "]"};
		Node<Lexem>* current = _lexems.begin();
		int current_pos = 0;
		while (current != nullptr) {
			if (current->get_data().get_type() == BRACKET) {
				int i;
				for (i = 0; i < num_of_valid_brackets; i++) {
					if (current->get_data().get_name() == valid_brackets[i]) {
						break;
					}
				}
				if (i == num_of_valid_brackets) {
					DescriptionError error;
					error.type = TYPE_ERROR::UNVALID_BRACKET;
					error.pos = current_pos;
					return error;
				}
				else if (i % 2 == 0) {
					brackets.push(valid_brackets[i]);
				}
				else if (!brackets.isEmpty()) {
					std::string tmp = brackets.top();
					if (tmp == valid_brackets[i - 1]) {
						brackets.pop();
					}
					else {
						DescriptionError error;
						error.type = TYPE_ERROR::MISMATCHED_BRACKET;
						error.pos = current_pos;
						return error;
					}
				}
				else {
					DescriptionError error;
					error.type = TYPE_ERROR::EXTRA_BRACKET;
					error.pos = current_pos;
					return error;
				}
			}
			current = current->get_next();
			current_pos++;
		}
		if (!brackets.isEmpty()) {
			DescriptionError error;
			error.type = TYPE_ERROR::MISSING_BRACKET;
			error.pos = current_pos;
			return error;
		}
		DescriptionError error;
		error.type = TYPE_ERROR::NON_ERROR;
		error.pos = -1;
		return error;
	}
	


}







#endif  // LIB_ALGORITHMS_ALGORITHMS_H
