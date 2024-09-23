#pragma once  //	include guard

#include <iostream>

template <typename T>
void iter(T* arr, size_t arrLen, void (*func)(T&)) {
  if (arr == NULL && func == NULL) return;
  for (size_t i = 0; i < arrLen; i++) func(arr[i]);
}
