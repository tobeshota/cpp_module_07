#include "iter.hpp"

// テスト用関数：引数を1増加させる
template <typename T>
void increment(T& elem) {
  elem++;
}

template <typename T>
static void putElement(T* arr, size_t arrLen) {
  for (size_t i = 0; i < arrLen; i++) std::cout << arr[i] << " ";
  std::cout << std::endl;
}

// 配列が正しく更新されることを確認するテスト
int main(void) {
  int arr[] = {1, 2, 3, 4, 5};
  size_t arrLen = sizeof(arr) / sizeof(arr[0]);

  // iter関数を使用して配列の各要素を1増加させる
  iter(arr, arrLen, increment);

  // 各要素が1増加しているか確認
  putElement(arr, arrLen);
}
