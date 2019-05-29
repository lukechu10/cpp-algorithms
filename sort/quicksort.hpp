#pragma once

#include <iostream>
#include <utility> // std::swap

namespace Sort {

namespace QuickSort {

template <typename Container>
unsigned partition(Container &c, int low, int high) {
  auto pivot = c[high]; // place pivot at last element
  auto i = (low - 1);

  for (unsigned j = low; j <= high - 1; j++) {
    // if element is smaller or equal to pivot
    if (c[j] <= pivot) {
      i++; // increment index of smaller element
      swap(c[i], c[j]);
    }
  }
  swap(c[i + 1], c[high]);
  return (i + 1);
}

template <typename Container>
// low = starting index high = ending index
void sort(Container &c, int low, int high) {
  if (low < high) {
    unsigned pi = partition(c, low, high); // partition index

    // Sort element before and after partition
    sort(c, low, pi - 1);
    sort(c, pi + 1, high);
  }
}

template <typename Container> void sort(Container &c) {
  sort(c, 0, c.size() - 1);
}
} // namespace QuickSort
} // namespace Sort