#include <gtest/gtest.h>

#include "iter.hpp"  // iter関数を含む

// テスト用関数：引数を1増加させる
template <typename T>
void increment(T& elem) {
  elem++;
}

// 配列が正しく更新されることを確認するテスト
TEST(IterFunctionTest, IncrementArray) {
  int arr[] = {1, 2, 3, 4, 5};
  size_t arrLen = sizeof(arr) / sizeof(arr[0]);

  // iter関数を使用して配列の各要素を1増加させる
  iter(arr, arrLen, increment);

  // 各要素が1増加しているか確認
  EXPECT_EQ(arr[0], 2);
  EXPECT_EQ(arr[1], 3);
  EXPECT_EQ(arr[2], 4);
  EXPECT_EQ(arr[3], 5);
  EXPECT_EQ(arr[4], 6);
}

// 空の配列に対するテスト
TEST(IterFunctionTest, EmptyArray) {
  int* emptyArr = nullptr;
  size_t arrLen = 0;

  // 空の配列に対してiterを適用してもエラーが出ないか確認
  iter(emptyArr, arrLen, increment);
  // 特に何も検証することはないが、クラッシュしないことが重要
}

// 文字列配列に対するテスト
TEST(IterFunctionTest, StringArray) {
  std::string arr[] = {"hello", "world"};
  size_t arrLen = sizeof(arr) / sizeof(arr[0]);

  // iter関数を使用して各文字列に "!" を追加する関数を作成
  void (*appendExclamation)(std::string&) = [](std::string& str) {
    str += "!";
  };

  iter(arr, arrLen, appendExclamation);

  EXPECT_EQ(arr[0], "hello!");
  EXPECT_EQ(arr[1], "world!");
}

// const引数の関数ポインタに対するテスト
TEST(IterFunctionTest, ConstArg) {
  std::string arr[] = {"FAILURE", "SUCCESS"};
  size_t arrLen = sizeof(arr) / sizeof(arr[0]);

  // iter関数を使用して各文字列を強調して出力する関数を作成
  void (*emphasizeStr)(const std::string&) = [](const std::string& str) {
    std::cout << ">>>>>>>>>> " << str << " <<<<<<<<<<\n";
  };

  testing::internal::CaptureStdout();  // 標準出力キャプチャ開始
  iter(arr, arrLen, emphasizeStr);
  std::string actual =
      testing::internal::GetCapturedStdout();  // 標準出力のキャプチャ結果を取得
  std::string expect =
      ">>>>>>>>>> FAILURE <<<<<<<<<<\n>>>>>>>>>> SUCCESS <<<<<<<<<<\n";  // 望まれる標準出力を定義
  EXPECT_EQ(expect, actual);
}
