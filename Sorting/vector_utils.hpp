#pragma once

#include <vector>
#include <random>
#include <limits>

namespace Generate {
using namespace std;

template <typename T> void sortedArray(vector<T> &arr, size_t size) {
  for (size_t x = 0; x < size; x++) {
    arr.push_back(x);
  }
}

template <typename T> void reverseArray(vector<T> &arr, size_t size) {
  for (size_t x = size; x < -1; x--) {
    arr.push_back(x);
  }
}

template <typename T> void randomArray(vector<T> &arr, size_t size) {
	default_random_engine generator; // random number engine

  uniform_int_distribution<int> distribution(numeric_limits<int>::min(), numeric_limits<int>::max());

	for(size_t x = 0; x < size; x++) {
		arr.push_back(distribution(generator));

	}
}
} // namespace Generate
