#pragma once

#include <iostream>

template <typename T>
class Array {
 private:
  T* _array;
  unsigned int _n;

 public:
  Array() : _array(NULL), _n(0) {}

  Array(unsigned int n) : _n(n) { _array = new T[n](); }

  Array(const Array& other) : _n(other._n) {
    _array = new T[_n];
    for (unsigned int i = 0; i < _n; i++) {
      _array[i] = other._array[i];
    }
  }

  Array& operator=(const Array& other) {
    if (this != &other) {
      _n = other._n;
      delete[] _array;
      _array = new T[_n];
      for (unsigned int i = 0; i < _n; i++) {
        _array[i] = other._array[i];
      }
    }
    return *this;
  }

  ~Array() { delete[] _array; }

  T& operator[](unsigned int index) {
    if (index >= _n) {
      throw std::out_of_range("index is out of bounds");
    }
    return _array[index];
  }

  unsigned int size() const { return _n; }
};
