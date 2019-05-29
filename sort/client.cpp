#include <cctype>
#include <chrono>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "../stopwatch.hpp"

#include "quicksort.hpp"

int main() {
  vector<long long> vec;

  // ask user for choice
  /*
int ans;
cout << ">"; // show input prompt
cin >> ans;
switch (ans) {}
   */

  cout << "Enter numbers. Once finished, enter 'q' to exit.\n";

  string input;
  cout << ">";
  while (cin >> input) {
    if (!isdigit(input[0]) && input[0] != '-') {
      if (input[0] == 'q') {
        // check if vec.size() != 0
        if (vec.size() == 0) {
          cout << "You need to enter some numbers!\n";
          continue;
        }
        break;
      } else {
        cout << "Unknown token\n";
        continue;
      }
    } else if (stoll(input) > 9223372036854775807 ||
               stoll(input) < -9223372036854775807) {
      // To-Do replace with <limits> library
      cout << "Number must be between -9223372036854775808 and "
              "9223372036854775807\n";
      continue;
    }
    vec.push_back(stoll(input));
    cout << ">";
  }

  cout << vec.size() << "Numbers to be sorted:\n";
  for (auto x : vec) {
    cout << x << "\t";
  }

  StopWatch sw;
  sw.start();

  Sort::QuickSort::sort(vec);

  auto tElapsed = sw.duration().count(); // save benchmark

  cout << "\nSorted numbers using quick sort:\n";
  for (auto x : vec) {
    cout << x << "\t";
  }

  cout << "\nTime elapsed: " << fixed << tElapsed << " seconds\n";

  return 0;
}