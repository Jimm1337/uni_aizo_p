#ifndef UNI_AIZO_P_AIZO_TOOL_ARRAYGENERATOR_HPP
#define UNI_AIZO_P_AIZO_TOOL_ARRAYGENERATOR_HPP

#include "aizo_sort_quick.hpp"
#include <random>

namespace aizo::tool {

/**
 * @brief Class to generate arrays with different properties.
 * @headerfile aizo_tool_arraygenerator.hpp
 *
 * @tparam Type Type of the elements in the array.
 * @tparam SortFunction Sort function type. For generating sorted arrays.
 *
 * @attention Type must be an arithmetic type.
 *
 * @note Uses quick sort from this library to sort the arrays.
 */
template< typename Type >
requires std::is_arithmetic_v< Type >
class ArrayGenerator {
public:
  /**
   * @brief Construct a new Array Generator object.
   * @param size Size of the array to generate.
   */
  explicit ArrayGenerator(std::size_t size): size{ size } {
  }

  /**
   * @brief Generate a pure random array.
   * @param min Minimum value of the array.
   * @param max Maximum value of the array.
   * @return Random array.
   */
  ds::DynamicArray< Type > generatePureRandom(Type min, Type max) {
    ds::DynamicArray< Type > array{};
    array.resize(size);

    std::random_device device{};
    std::mt19937       generator{ device() };

    if constexpr (std::is_floating_point_v< Type >) {
      std::uniform_real_distribution< Type > distribution{ min, max };
      for (auto& element : array) { element = distribution(generator); }
    } else {
      std::uniform_int_distribution< Type > distribution{ min, max };
      for (auto& element : array) { element = distribution(generator); }
    }

    return array;
  }

  /**
   * @brief Generate a random sorted array. (Ascending)
   * @param min Minimum value of the array.
   * @param max Maximum value of the array.
   * @return Sorted ascending array.
   */
  ds::DynamicArray< Type > generateSortedAscending(Type min, Type max) {
    auto array = generatePureRandom(min, max);

    sort::quick::classic(std::begin(array), std::end(array));

    return array;
  }

  /**
   * @brief Generate a random sorted array. (Descending)
   * @param min Minimum value of the array.
   * @param max Maximum value of the array.
   * @return Sorted descending array.
   */
  ds::DynamicArray< Type > generateSortedDescending(Type min, Type max) {
    auto array = generatePureRandom(min, max);

    sort::quick::classic(std::begin(array), std::end(array), std::greater<>{});

    return array;
  }

  /**
   * @brief Generate a one-third sorted array. (Ascending)
   * @param min Minimum value of the array.
   * @param max Maximum value of the array.
   * @return One-third sorted ascending array.
   */
  ds::DynamicArray< Type > generateOneThirdSortedAscending(Type min, Type max) {
    auto array = generatePureRandom(min, max);

    const auto oneThird = size / 3;
    sort::quick::classic(std::begin(array),
                         std::next(std::begin(array), oneThird));

    return array;
  }

  /**
   * @brief Generate a one-third sorted array. (Descending)
   * @param min Minimum value of the array.
   * @param max Maximum value of the array.
   * @return One-third sorted descending array.
   */
  ds::DynamicArray< Type > generateOneThirdSortedDescending(Type min, Type max) {
    auto array = generatePureRandom(min, max);

    const auto oneThird = size / 3;
    sort::quick::classic(std::begin(array),
                         std::next(std::begin(array), oneThird),
                         std::greater<>{});

    return array;
  }

  /**
   * @brief Generate a two-thirds sorted array. (Ascending)
   * @param min Minimum value of the array.
   * @param max Maximum value of the array.
   * @return Two-thirds sorted ascending array.
   */
  ds::DynamicArray< Type > generateTwoThirdsSortedAscending(Type min, Type max) {
    auto array = generatePureRandom(min, max);

    const auto twoThirds = size * 2 / 3;
    sort::quick::classic(std::begin(array),
                         std::next(std::begin(array), twoThirds));

    return array;
  }

  /**
   * @brief Generate a two-thirds sorted array. (Descending)
   * @param min Minimum value of the array.
   * @param max Maximum value of the array.
   * @return Two-thirds sorted descending array.
   */
  ds::DynamicArray< Type > generateTwoThirdsSortedDescending(Type min, Type max) {
    auto array = generatePureRandom(min, max);

    const auto twoThirds = size * 2 / 3;
    sort::quick::classic(std::begin(array),
                         std::next(std::begin(array), twoThirds),
                         std::greater<>{});

    return array;
  }

private:
  std::size_t size{};
};

} // namespace aizo::tool

#endif // UNI_AIZO_P_AIZO_TOOL_ARRAYGENERATOR_HPP
