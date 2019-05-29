#pragma once

#include <chrono>
#include <ctime>
#include <functional>

class StopWatch {

public:
  StopWatch() {}
  StopWatch &start() noexcept {
    tStart = std::chrono::steady_clock::now();
    return *this;
  }

  // returns time elapsed in milliseconds
  std::chrono::duration<double> duration() noexcept {
    std::chrono::steady_clock::time_point tNow =
        std::chrono::steady_clock::now();
    std::chrono::duration<double> tSpan =
        std::chrono::duration_cast<std::chrono::nanoseconds>(tNow - tStart);
    return tSpan;
  }
  // StopWatch &stop();
  StopWatch &reset() {
    tStart = std::chrono::steady_clock::now();
    return *this;
  }

private:
  std::chrono::steady_clock::time_point tStart;
};