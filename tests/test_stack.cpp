#include "stack.h"
#include <gtest.h>

TEST(TStack, can_create_stack_with_positive_size) {

	ASSERT_NO_THROW(TStack<int> st(5));
}

TEST(TStack, cant_create_stack_with_negative_size) {
	ASSERT_ANY_THROW(TStack<int> st(-5));
}

TEST(TStack, can_set_and_get_element) {
	TStack<int> st(5);
	st.push(1);

	EXPECT_EQ(1, st.top());
}

TEST(TStack, can_delete_element) {
	TStack<int> st(5);
	st.push(1);
	st.push(2);
	st.pop();

	EXPECT_EQ(1, st.top());
}

TEST(TStack, cant_set_element_into_full_stack) {
	TStack<int> st(3);
	st.push(1);
	st.push(2);
	st.push(3);

	ASSERT_ANY_THROW(st.push(4));
}

TEST(TStack, cant_get_element_from_empty_stack) {
	TStack<int> st(3);

	ASSERT_ANY_THROW(st.top());
}