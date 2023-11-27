// Copyright 2023 Aleksey Lavrentyev

#ifndef LIB_ALGORITHMS_ALGORITHMS_H
#define LIB_ALGORITHMS_ALGORITHMS_H
//в лексемы добавить перегрузить оператор присваивания = , в списке посмотреть конструктор копирования, доделать тесты
#include <string>
#include "../lib_list/list.h"
#include "../lib_stack_on_list/stackOnList.h"
//extra лишняя закрытая, missing лишняя открытая
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
