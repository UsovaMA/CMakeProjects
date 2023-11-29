// Copyright 2023 Aleksey Lavrentyev
#include <string>
#include <gtest.h>
#include "../lib_stack/stack.h"

TEST(Stack, can_create_stack_with_positive_size) {
	ASSERT_NO_THROW(Stack<int> s1(10));
	}
TEST(Stack, cant_create_stack_with_negative_size) {
	ASSERT_ANY_THROW(Stack<int> s1(-10));
}
TEST(Stack, can_get_size_correctly) {
	Stack<int> s1(10);
	int expected_size = 10;
	int current_size;
	ASSERT_NO_THROW(current_size = s1.size());
	EXPECT_EQ(expected_size, current_size);
}
TEST(Stack, can_convert_stack_to_string_correctly) {
	Stack<int> s1(5);
	for (int i = 0; i < 5; i++)
		s1.push(i + 1);
	std::string expected_str = "5\n4\n3\n2\n1\n";
	std::string current_str;
	ASSERT_NO_THROW(current_str = s1.toString());
	EXPECT_EQ(expected_str, current_str);
}
TEST(Stack, can_convert_empty_stack_to_string) {
	Stack<int> s1(5);
	std::string expected_str = "<empty>";
	std::string current_str;
	ASSERT_NO_THROW(current_str = s1.toString());
	EXPECT_EQ(expected_str, current_str);
}
TEST(Stack, can_push_correctly) {
	Stack<int> s1(5);
	s1.push(1);
	EXPECT_EQ(s1.top(), 1);
}

TEST(Stack, throw_push_in_full_stack) {
	Stack<int> s1(5);
	for (int i = 0; i < 5; i++)
		s1.push(i + 1);
	ASSERT_ANY_THROW(s1.push(5));
}

TEST(Stack, can_pop_correctly) {
	Stack<int> s1(5);
	for (int i = 0; i < 5; i++)
		s1.push(i + 1);
	s1.pop();
	EXPECT_EQ(s1.top(), 4);
}

TEST(Stack, throw_pop_from_empty_stack) {
	Stack<int> s1(5);
	ASSERT_ANY_THROW(s1.pop());
}

TEST(Stack, throw_top_from_empty_stack) {
	Stack<int> s1(5);
	ASSERT_ANY_THROW(s1.top());
}

TEST(Stack, can_return_top_element_correctly) {
	Stack<int> s1(5);
	s1.push(7);
	s1.push(-3);
	EXPECT_EQ(s1.top(), -3);
}

TEST(Stack, return_true_isEmpty) {
	Stack<int> s1(5);
	EXPECT_EQ(s1.isEmpty(), 1);
	EXPECT_EQ(s1.isFull(), 0);
}

TEST(Stack, return_true_isFull) {
	Stack<int> s1(3);
	s1.push(3);
	s1.push(4);
	s1.push(3);
	EXPECT_EQ(s1.isFull(), 1);
}

/*TEST(Stack, ) {
	Stack<int> s1(5);
}
TEST(Stack, ) {
	Stack<int> s1(5);
}
TEST(Stack, ) {
	Stack<int> s1(5);
}
TEST(Stack, ) {
	Stack<int> s1(5);
}
TEST(Stack, ) {
	Stack<int> s1(5);
}
TEST(Stack, ) {
	Stack<int> s1(5);
}
TEST(Stack, ) {
	Stack<int> s1(5);
}*/