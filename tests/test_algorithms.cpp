// Copyright 2023 Aleksey Lavrentyev
#include <string>
#include <gtest.h>
#include "../lib_algorithms/algorithms.h"

TEST(SequencesBrackets, can_check_correct_sequences) {
	//{()([][])}
	List<Lexem> lexems;
	Lexem tmp("{", BRACKET);
	lexems.push_back(tmp);
	tmp.set_values("(", BRACKET);
	lexems.push_back(tmp);
	tmp.set_values(")", BRACKET);
	lexems.push_back(tmp);
	tmp.set_values("(", BRACKET);
	lexems.push_back(tmp);
	tmp.set_values("[", BRACKET);
	lexems.push_back(tmp);
	tmp.set_values("]", BRACKET);
	lexems.push_back(tmp);
	tmp.set_values("[", BRACKET);
	lexems.push_back(tmp);
	tmp.set_values("]", BRACKET);
	lexems.push_back(tmp);
	tmp.set_values(")", BRACKET);
	lexems.push_back(tmp);
	tmp.set_values("}", BRACKET);
	lexems.push_back(tmp);
	DescriptionError error = parser::check_brackets(lexems);
	EXPECT_EQ(error.pos, -1);
	EXPECT_EQ(TYPE_ERROR::NON_ERROR, error.type);
}
