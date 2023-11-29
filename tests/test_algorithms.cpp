// Copyright 2023 Aleksey Lavrentyev
#include <string>
#include <gtest.h>
#include "../lib_algorithms/algorithms.h"

TEST(SequencesBrackets, can_check_correct_sequences_no_error) {
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

TEST(SequencesBrackets, can_check_correct_sequences_missmatched_brackets) {
	//({)([][])}
	List<Lexem> lexems;
	Lexem tmp("(", BRACKET);
	lexems.push_back(tmp);
	tmp.set_values("{", BRACKET);
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
	EXPECT_EQ(error.pos, 2);
	EXPECT_EQ(TYPE_ERROR::MISMATCHED_BRACKET, error.type);
}

TEST(SequencesBrackets, can_check_correct_sequences_extra_bracket) {
	//{())([][])}
	List<Lexem> lexems;
	Lexem tmp("{", BRACKET);
	lexems.push_back(tmp);
	tmp.set_values("(", BRACKET);
	lexems.push_back(tmp);
	tmp.set_values(")", BRACKET);
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
	EXPECT_EQ(error.pos, 3);
	EXPECT_EQ(TYPE_ERROR::EXTRA_BRACKET, error.type);
}

TEST(SequencesBrackets, can_check_correct_sequences_unvalid_bracket) {
	//{')([][])}
	List<Lexem> lexems;
	Lexem tmp("{", BRACKET);
	lexems.push_back(tmp);
	tmp.set_values("'", BRACKET);
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
	EXPECT_EQ(error.pos, 1);
	EXPECT_EQ(TYPE_ERROR::UNVALID_BRACKET, error.type);
}
//при лишней скобке поз еррор указывает на последнюю скобку
TEST(SequencesBrackets, can_check_correct_sequences_missing_bracket) {
	//{{()([][])}
	List<Lexem> lexems;
	Lexem tmp("{", BRACKET);
	lexems.push_back(tmp);
	tmp.set_values("{", BRACKET);
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
	EXPECT_EQ(error.pos, 11);
	EXPECT_EQ(TYPE_ERROR::MISSING_BRACKET, error.type);
}