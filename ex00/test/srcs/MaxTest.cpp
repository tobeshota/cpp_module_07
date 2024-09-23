#include <gtest/gtest.h>

#include "whatever.hpp"

template <typename T>
void maxTest(T& minValue, T& maxValue) {
  T ret = ::max(minValue, maxValue);
  EXPECT_EQ(maxValue, ret);
}

TEST(MaxTest, charTest) {
  char value[] = {'a', 'b', 'c', 'd'};
  maxTest(value[0], value[0]);
  maxTest(value[0], value[1]);
  maxTest(value[1], value[2]);
  maxTest(value[2], value[3]);
}

TEST(MaxTest, intTest) {
  int value[] = {0, 1, 2, 3};
  maxTest(value[0], value[0]);
  maxTest(value[0], value[1]);
  maxTest(value[1], value[2]);
  maxTest(value[2], value[3]);
}

TEST(MaxTest, floatTest) {
  float value[] = {0.1f, 0.2f, 0.2f, 0.3f};
  maxTest(value[0], value[0]);
  maxTest(value[0], value[1]);
  maxTest(value[1], value[2]);
  maxTest(value[2], value[3]);
}

TEST(MaxTest, doubleTest) {
  double value[] = {0.1, 0.2, 0.2, 0.3};
  maxTest(value[0], value[0]);
  maxTest(value[0], value[1]);
  maxTest(value[1], value[2]);
  maxTest(value[2], value[3]);
}

TEST(MaxTest, stringTest) {
  std::string value[] = {"AAA", "BBB", "CCC", "DDD"};
  maxTest(value[0], value[0]);
  maxTest(value[0], value[1]);
  maxTest(value[1], value[2]);
  maxTest(value[2], value[3]);
}
