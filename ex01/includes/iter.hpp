#pragma once  //	include guard

#include <iostream>

template <typename T>
void iter(T* arr, size_t arrLen, void (*func)(T&)) {
  if (arr == NULL && func == NULL) return;
  for (size_t i = 0; i < arrLen; i++) func(arr[i]);
}

// const引数の関数ポインタに対してはこのテンプレート関数が発火する
template <typename T>
void iter(const T* arr, size_t arrLen, void (*func)(const T&)) {
  if (arr == NULL && func == NULL) return;
  for (size_t i = 0; i < arrLen; i++) func(arr[i]);
}
