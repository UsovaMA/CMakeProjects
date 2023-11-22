#include "list.h"
#include <gtest.h>

TEST(TList, can_create_list_from_mass) {
	int* mass = new int[10];
	ASSERT_NO_THROW(TList<int> l(mass[1, 2, 3]));
}

TEST(TList, can_set_element_into_tail) {
	TList<int> l();

	ASSERT_NO_THROW(l.push_back(10));
}

TEST(TVector, can_set_element_into_head) {
	TList<int> l();

	ASSERT_NO_THROW(l.push_front(10));
}

TEST(TVector, can_set_and_element_anywhere) {
	TList<int> l();

	ASSERT_NO_THROW(l.insert(tail, 10));
}