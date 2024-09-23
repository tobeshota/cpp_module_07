#include <gtest/gtest.h>

#include "Array.hpp"  // Arrayクラスの実装ファイル

// デフォルトコンストラクタのテスト
TEST(ArrayTest, DefaultConstructor) {
  Array<int> arr;
  // 配列のサイズが0であることを確認
  EXPECT_EQ(arr.size(), 0);
}

// サイズ指定コンストラクタのテスト
TEST(ArrayTest, SizeConstructor) {
  Array<int> arr(5);
  // サイズが正しく設定されていることを確認
  EXPECT_EQ(arr.size(), 5);
  for (unsigned int i = 0; i < arr.size(); i++) {
    // 要素がデフォルトで初期化されていることを確認（intの場合は0）
    EXPECT_EQ(arr[i], 0);
  }
}

// コピーコンストラクタのテスト
TEST(ArrayTest, CopyConstructor) {
  Array<int> arr(5);
  for (unsigned int i = 0; i < arr.size(); i++) {
    arr[i] = i * 10;
  }

  Array<int> copyArr(arr);  // コピーコンストラクタで複製
  EXPECT_EQ(copyArr.size(), arr.size());

  for (unsigned int i = 0; i < arr.size(); i++) {
    EXPECT_EQ(copyArr[i], arr[i]);  // 元の配列と同じ値を持つか確認
  }

  copyArr[0] = 100;               // コピーした配列を変更
  EXPECT_NE(arr[0], copyArr[0]);  // 元の配列が影響を受けないことを確認
}

// 代入演算子のテスト
TEST(ArrayTest, AssignmentOperator) {
  Array<int> arr(5);
  for (unsigned int i = 0; i < arr.size(); i++) {
    arr[i] = i * 10;
  }

  Array<int> assignedArr;
  assignedArr = arr;  // 代入演算子で複製
  EXPECT_EQ(assignedArr.size(), arr.size());

  for (unsigned int i = 0; i < arr.size(); i++) {
    EXPECT_EQ(assignedArr[i], arr[i]);  // 元の配列と同じ値を持つか確認
  }

  assignedArr[0] = 100;
  EXPECT_NE(arr[0], assignedArr[0]);  // 元の配列が影響を受けないことを確認
}

// 添字演算子のテスト
TEST(ArrayTest, SubscriptOperator) {
  Array<int> arr(5);
  for (unsigned int i = 0; i < arr.size(); i++) {
    arr[i] = i * 10;
  }

  EXPECT_EQ(arr[0], 0);
  EXPECT_EQ(arr[1], 10);
  EXPECT_EQ(arr[4], 40);

  arr[0] = 100;
  EXPECT_EQ(arr[0], 100);
}

// 範囲外アクセスのテスト
TEST(ArrayTest, OutOfBoundsAccess) {
  Array<int> arr(5);
  // 範囲外アクセスで例外をスローすることを確認
  EXPECT_THROW(arr[10], std::out_of_range);
  // マイナスのインデックスで例外をスローすることを確認
  EXPECT_THROW(arr[-1], std::out_of_range);
}

// size()メンバ関数のテスト
TEST(ArrayTest, SizeFunction) {
  Array<int> arr(5);
  EXPECT_EQ(arr.size(), 5);  // サイズが正しく返されることを確認
}

// メモリリークがないかを確認するための基本的なテスト
TEST(ArrayTest, NoMemoryLeak) {
  Array<int> arr(1000);  // 大きな配列を作成しても、エラーが発生しないことを確認
  for (unsigned int i = 0; i < arr.size(); i++) {
    arr[i] = i;
  }
}

// 独立した配列の変更を確認するテスト
TEST(ArrayTest, IndependentCopy) {
  Array<int> arr(5);
  for (unsigned int i = 0; i < arr.size(); i++) {
    arr[i] = i * 10;
  }

  Array<int> copyArr = arr;
  copyArr[0] = 100;      // コピーされた配列を変更
  EXPECT_EQ(arr[0], 0);  // 元の配列は変更されていないことを確認
}
