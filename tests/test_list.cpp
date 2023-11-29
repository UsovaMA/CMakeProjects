// Copyright 2023 Aleksey Lavrentyev
#include <string>
#include <gtest.h>
#include "../lib_list/list.h"

TEST(Node, can_create_empty_node_correctly) {
	Node<int> n;
	EXPECT_EQ(n.get_data(), NULL);
	EXPECT_EQ(n.get_next(), nullptr);
}
TEST(Node, can_create_node_with_data_correctly) {
	Node<int> n(1);
	EXPECT_EQ(n.get_data(), 1);
	EXPECT_EQ(n.get_next(), nullptr);
}
/// <summary>
/// ///////////
/// </summary>
/// <param name=""></param>
/// <param name=""></param>
TEST(Node, can_create_node_with_data_and_next_correctly) {
	Node<int> n(1);
	Node<int> n1(2, &n);

	EXPECT_EQ(n1.get_data(), 2);
	EXPECT_EQ(n1.get_next(), &n);
}

TEST(Node, can_convert_node_to_string_correctly) {
	Node<int> n(1);
	Node<int> n1(2, &n);
	Node<int> n2(2, &n1);
	std::string expected_str = "1->NULL";
	std::string expected_str1 = "2->";
	std::string current_str = n.toString();
	ASSERT_NO_THROW(current_str = n.toString());
	EXPECT_EQ(expected_str, current_str);
	current_str = n1.toString();
	ASSERT_NO_THROW(current_str = n1.toString());
	EXPECT_EQ(expected_str1, current_str);
}


TEST(Node, can_assign_node_correctly) {
	Node<int> n(5);
	Node<int> n1(5, &n);
	Node<int> n2 = n1;
	EXPECT_EQ(n2.get_data(), n1.get_data());
	EXPECT_EQ(n2.get_next(), n1.get_next());
}

TEST(Node, can_compare_correctly) {
	Node<int> n(1);
	Node<int> n1(1);
	Node<int> n2(2);
	Node<int> n3(3);
	EXPECT_EQ(n == n1, 1);
	EXPECT_EQ(n < n1, 0);
	EXPECT_EQ(n < n2, 1);
	EXPECT_EQ(n > n1, 0);
	EXPECT_EQ(n3 > n1, 1);
}

/////////////////////////////////LIST/////////////////////////////////

TEST(List, can_push_front_correctly_and_get_front) {
	List<int> l;
	l.push_front(1);
	l.push_front(2);
	EXPECT_EQ(2, l.get_head());
}

TEST(List, throw_get_head_from_empty_list) {
	List<int> l;
	ASSERT_ANY_THROW(l.get_head());
}

TEST(List, return_isEmpty_correctly) {
	List<int> l;
	EXPECT_EQ(l.isEmpty(), 1);
	l.push_front(1);
	EXPECT_EQ(l.isEmpty(), 0);
}

TEST(List, can_clear_list_correclty) {
	List<int> l;
	l.push_front(1);
	l.push_front(-4);
	l.push_front(0);
	l.clear();
	EXPECT_EQ(l.isEmpty(), 1);
}

TEST(List, can_pop_front_correctly) {
	List<int> l;
	l.push_front(-4);
	l.push_front(0);
	l.push_front(1);
	l.pop_front();
	EXPECT_EQ(l.get_head(), 0);
}

TEST(List, throws_get_head_from_empty_list) {
	List<int> l;
	ASSERT_ANY_THROW(l.get_head());
}


/*
TEST(List, ) {
	List<int> l;

}
*/