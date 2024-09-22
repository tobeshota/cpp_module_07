#include <gtest/gtest.h>
#include "whatever.hpp"

template <typename T>
void minTest(T& minValue, T& maxValue) {
	T ret = ::min(minValue, maxValue);
	EXPECT_EQ(minValue, ret);
}

TEST(MinTest, charTest) {
	char value[] = {'a', 'b', 'c', 'd'};
	minTest(value[0], value[0]);
	minTest(value[0], value[1]);
	minTest(value[1], value[2]);
	minTest(value[2], value[3]);
}

TEST(MinTest, intTest) {
	int value[] = {0, 1, 2, 3};
	minTest(value[0], value[0]);
	minTest(value[0], value[1]);
	minTest(value[1], value[2]);
	minTest(value[2], value[3]);
}

TEST(MinTest, floatTest) {
	float value[] = {0.1f, 0.2f, 0.2f, 0.3f};
	minTest(value[0], value[0]);
	minTest(value[0], value[1]);
	minTest(value[1], value[2]);
	minTest(value[2], value[3]);
}

TEST(MinTest, doubleTest) {
	double value[] = {0.1, 0.2, 0.2, 0.3};
	minTest(value[0], value[0]);
	minTest(value[0], value[1]);
	minTest(value[1], value[2]);
	minTest(value[2], value[3]);
}

TEST(MinTest, stringTest) {
	std::string value[] = {"AAA", "BBB", "CCC", "DDD"};
	minTest(value[0], value[0]);
	minTest(value[0], value[1]);
	minTest(value[1], value[2]);
	minTest(value[2], value[3]);
}
