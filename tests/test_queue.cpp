// Copyright 2023 Aleksey Lavrentyev
#include <string>
#include <gtest.h>
#include "../lib_queue/queue.h"

TEST(Queue, can_create_Queue_with_positive_size) {
	ASSERT_NO_THROW(Queue<int> s1(10));
}
TEST(Queue, cant_create_Queue_with_negative_size) {
	ASSERT_ANY_THROW(Queue<int> s1(-10));
}
TEST(Queue, can_get_size_correctly) {
	Queue<int> s1(10);
	int expected_size = 10;
	int current_size;
	ASSERT_NO_THROW(current_size = s1.size());
	EXPECT_EQ(expected_size, current_size);
}
TEST(Queue, can_convert_Queue_to_string_correctly) {
	Queue<int> s1(5);
	for (int i = 0; i < 5; i++)
		s1.push(i + 1);
	std::string expected_str = "1\n2\n3\n4\n5\n";
	std::string current_str;
	ASSERT_NO_THROW(current_str = s1.toString());
	EXPECT_EQ(expected_str, current_str);
}
TEST(Queue, can_convert_empty_Queue_to_string) {
	Queue<int> s1(5);
	std::string expected_str = "<empty>";
	std::string current_str;
	ASSERT_NO_THROW(current_str = s1.toString());
	EXPECT_EQ(expected_str, current_str);
}
TEST(Queue, can_push_correctly) {
	Queue<int> s1(5);
	s1.push(1);
	s1.push(2);
	EXPECT_EQ(s1.back(), 2);
}

TEST(Queue, can_return_front_element_correctly) {
	Queue<int> s1(5);
	s1.push(1);
	s1.push(2);
	EXPECT_EQ(s1.front(), 1);
}

TEST(Queue, throw_push_in_full_Queue) {
	Queue<int> s1(5);
	for (int i = 0; i < 5; i++)
		s1.push(i + 1);
	ASSERT_ANY_THROW(s1.push(5));
}

TEST(Queue, can_pop_correctly) {
	Queue<int> s1(5);
	for (int i = 0; i < 5; i++)
		s1.push(i + 1);
	s1.pop();
	EXPECT_EQ(s1.front(), 2);
}

TEST(Queue, throw_pop_from_empty_Queue) {
	Queue<int> s1(5);
	ASSERT_ANY_THROW(s1.pop());
}

TEST(Queue, throw_top_and_back_from_empty_Queue) {
	Queue<int> s1(5);
	ASSERT_ANY_THROW(s1.back());
	ASSERT_ANY_THROW(s1.front());
}

TEST(Queue, return_true_isEmpty) {
	Queue<int> s1(5);
	EXPECT_EQ(s1.isEmpty(), 1);
	EXPECT_EQ(s1.isFull(), 0);
}

TEST(Queue, return_true_isFull) {
	Queue<int> s1(3);
	s1.push(3);
	s1.push(4);
	s1.push(3);
	EXPECT_EQ(s1.isFull(), 1);
}