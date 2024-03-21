#include "aizo.hpp"
#include <array>
#include <list>
#include <vector>
#include <fmt/core.h>

int main() {
  std::vector arr = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };

  fmt::print("Before:\n");
  for (const auto& i : arr) { fmt::print("{} ", i); }

  aizo::sort::insertion::binary(std::begin(arr), std::end(arr));

  fmt::print("\nAfter:\n");
  for (const auto& i : arr) { fmt::print("{} ", i); }

  aizo::sort::insertion::classic(
    std::begin(arr), std::end(arr), std::greater{});

  fmt::print("\nAfter:\n");
  for (const auto& i : arr) { fmt::print("{} ", i); }

  return 0;
}
