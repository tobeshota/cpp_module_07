#pragma once  //	include guard

#include <iostream>

template <typename T>
class Array {
 private:
  T* _array;
  unsigned int _n;

 public:
  Array() : _array(NULL), _n(0) {
    std::cout << "(constructor)Array Default constructor called" << std::endl;
  }

  Array(unsigned int n) : _n(n) {
    std::cout << "(constructor)Array constructor called" << std::endl;
    _array = new T[n]();
    if (!_array) {
      throw std::bad_alloc();
    }
  }

  Array(const Array& other) : _n(other._n) {
    std::cout << "(constructor)Array Copy constructor called" << std::endl;
    if (_n > 0) {
      _array = new T[_n];
      if (!_array) {
        throw std::bad_alloc();
      }
      for (unsigned int i = 0; i < _n; i++) {
        _array[i] = other._array[i];
      }
    }
  }

  Array& operator=(const Array& other) {
    if (this != &other) {
      _n = other._n;
      if (_n > 0) {
        delete[] _array;
        _array = new T[_n];
        if (!_array) {
          throw std::bad_alloc();
        }
        for (unsigned int i = 0; i < _n; i++) {
          _array[i] = other._array[i];
        }
      }
    }
    return *this;
  }

  ~Array() {
    std::cout << "(destructor)Array destructor called" << std::endl;
    delete[] _array;
  }

  T& operator[](unsigned int index) {
    if (index >= _n) {
      throw std::out_of_range("index is out of bounds");
    }
    return _array[index];
  }

  unsigned int size() const { return _n; }
};
