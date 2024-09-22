#pragma once  //	include guard

#include <iostream>

template <typename T1>
void swap(T1& x, T1& y) {
  T1 tmp = x;
  x = y;
  y = tmp;
}

template <typename T2>
const T2& min(const T2& x, const T2& y) {
  return x <= y ? x : y;
}

template <typename T3>
const T3& max(const T3& x, const T3& y) {
  return x >= y ? x : y;
}
