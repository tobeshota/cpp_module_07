#include <gtest/gtest.h>
#include "whatever.hpp"

template <typename T>
void swapTest(T& x, T& y) {
	T beforeX = x;
	T beforeY = y;
	swap(x, y);
	EXPECT_EQ(x, beforeY);
	EXPECT_EQ(y, beforeX);
}

TEST(SwapTest, charTest) {
	char value[] = {'a', 'b', 'c', 'd'};
	swapTest(value[0], value[0]);
	swapTest(value[0], value[1]);
	swapTest(value[1], value[2]);
	swapTest(value[2], value[3]);
}

TEST(SwapTest, intTest) {
	int value[] = {0, 1, 2, 3};
	swapTest(value[0], value[0]);
	swapTest(value[0], value[1]);
	swapTest(value[1], value[2]);
	swapTest(value[2], value[3]);
}

TEST(SwapTest, floatTest) {
	float value[] = {0.1f, 0.2f, 0.2f, 0.3f};
	swapTest(value[0], value[0]);
	swapTest(value[0], value[1]);
	swapTest(value[1], value[2]);
	swapTest(value[2], value[3]);
}

TEST(SwapTest, doubleTest) {
	double value[] = {0.1, 0.2, 0.2, 0.3};
	swapTest(value[0], value[0]);
	swapTest(value[0], value[1]);
	swapTest(value[1], value[2]);
	swapTest(value[2], value[3]);
}

TEST(SwapTest, stringTest) {
	std::string value[] = {"AAA", "BBB", "CCC", "DDD"};
	swapTest(value[0], value[0]);
	swapTest(value[0], value[1]);
	swapTest(value[1], value[2]);
	swapTest(value[2], value[3]);
}
