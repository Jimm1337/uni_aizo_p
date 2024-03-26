#include "aizo.hpp"
#include <array>
#include <list>
#include <vector>
#include <fmt/core.h>
#include <fstream>

int main() {
  {
    aizo::tool::ArrayGenerator< int > gen{ 10000 };

    auto arr = gen.generateTwoThirdsSortedDescending(0, 1000);

    fmt::print("Before:\n");
    for (const auto& i : arr) { fmt::print("{} ", i); }

    aizo::tool::Timer timedSort{ [&arr] {
      aizo::sort::quick::classic(std::begin(arr), std::end(arr));
    } };

    timedSort();

    fmt::print("\nAfter:\n");
    for (const auto& i : arr) { fmt::print("{} ", i); }

    const auto [time, unit] = timedSort.getDurationStr();
    fmt::print("\n\nTime taken: {:.2f}{}\n", time, unit);
  }

  fmt::print("\n");
  fmt::print("-------------------------\n");

  {
    std::ifstream file{ DATA_DIR "test.arr" };
    aizo::tool::ArrayReader< int > reader{ std::istream_iterator< int >{ file } };

    auto [arr, size] = reader.read();

    fmt::print("Before:\n");
    for (const auto& i : arr) { fmt::print("{} ", i); }

    aizo::tool::Timer timedSort{ [&arr] {
      aizo::sort::heap::classic(std::begin(arr), std::end(arr));
    } };

    timedSort();

    fmt::print("\nAfter:\n");
    for (const auto& i : arr) { fmt::print("{} ", i); }

    const auto [time, unit] = timedSort.getDurationStr();
    fmt::print("\n\nTime taken: {:.2f}{}\n", time, unit);
  }
  return 0;
}
