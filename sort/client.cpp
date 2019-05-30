#include <cctype>
#include <chrono>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "../stopwatch.hpp"

#include "vector_utils.hpp"

#include "quicksort.hpp"

int main() {
  vector<long long> vec;

  // ask user for choice
  int ans;
generationChoice:
  cout << "Options:\n1) Enter numbers from input\n"
       << "2) Generate random array\n"
       << "3) Generate sorted array\n"
       << "4) Generate reversed array\n"
       << ">"; // show input prompt
  cin >> ans;
  switch (ans) {
  case 1:
    cout << "Enter numbers. Once finished, enter 'q' to exit.\n";
    {
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
    }
    break;
  case 2:
    cout << "Enter size of random array\n>";
    {
      int input;
      cin >> input;
      Generate::randomArray(vec, input);
    }
    break;
  case 3:
    cout << "Enter size of sorted array\n>";
    {
      int input;
      cin >> input;
      Generate::sortedArray(vec, input);
    }
    break;
  case 4:
    cout << "Enter size of reversed array\n>";
    {
      int input;
      cin >> input;
      Generate::reverseArray(vec, input);
    }
    break;
  default:
    cout << "Unknown input\n";
    // ask question again
    goto generationChoice;
  }

	cout << "Print numbers? (Default: no) Type '1' for yes\n>";
	
	bool printNumbers = false;
	cin >> printNumbers;

	if(printNumbers) {
		cout << "Numbers to be sorted:\n";
		for (auto x : vec) {
			cout << x << "\t";
		}
	}
  

  StopWatch sw;
  sw.start();

  Sort::QuickSort::sort(vec);

  auto tElapsed = sw.duration().count(); // save benchmark

	if(printNumbers) {
		cout << "\nSorted numbers using quick sort:\n";
		for (auto x : vec) {
			cout << x << "\t";
		}
	}
  

  cout << "\nTime elapsed: " << fixed << tElapsed << " seconds\n";

  return 0;
}