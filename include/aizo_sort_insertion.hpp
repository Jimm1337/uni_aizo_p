#ifndef UNI_AIZO_P_AIZO_SORT_INSERTION_HPP
#define UNI_AIZO_P_AIZO_SORT_INSERTION_HPP

#include "aizo_sort_insertion_impl.hpp"

/**
 * @brief Insertion sort algorithms.
 */
namespace aizo::sort::insertion {

/**
 * @brief Classic insertion sort algorithm.
 * @category Sort
 * @note Time complexity: O(n^2).
 * @headerfile aizo_sort_insertion.hpp
 *
 * @tparam Itr Iterator type.
 * @tparam Compare Comparison function type.
 * @param begin Iterator to the beginning of the range.
 * @param end Iterator to the end of the range.
 * @param compare Comparison function.
 *
 * @attention Requires Itr to be at least of category BidirectionalIterator.
 * @attention Requires Compare to be a function object that returns a boolean.
 *
 * @details Uses a nested loop to iterate over the range and swap elements one by one until they are in the correct order.
 */
template< typename Itr, typename Compare = std::less<> >
requires std::bidirectional_iterator< Itr > &&
         std::is_same_v< std::invoke_result_t< Compare,
                                               std::iter_value_t< Itr >,
                                               std::iter_value_t< Itr > >,
                         bool >
constexpr void classic(Itr begin, Itr end, Compare compare = Compare{}) {
  for (auto outerItr = begin; outerItr != end; outerItr = std::next(outerItr)) {
    for (auto innerItr = outerItr;
         innerItr != begin && compare(*innerItr, *(std::prev(innerItr)));
         innerItr = std::prev(innerItr)) {
      // If the current element is in the wrong position, swap it with the
      // previous element. Keep swapping until the current element is in the
      // correct position.
      std::iter_swap(innerItr, std::prev(innerItr));
    }
  }
}

/**
 * @brief Binary insertion sort algorithm.
 * @category Sort
 * @note Time complexity: O(n^2).
 * @headerfile aizo_sort_insertion.hpp
 *
 * @tparam Itr Iterator type.
 * @tparam Compare Comparison function type.
 * @param begin Iterator to the beginning of the range.
 * @param end Iterator to the end of the range.
 * @param compare Comparison function.
 *
 * @attention Requires Itr to be at least of category RandomAccessIterator.
 * @attention Requires Compare to be a function object that returns std::strong_ordering.
 *
 * @details Uses binary search to find the correct position for each element and then shifts the elements to make space for the new element.
 */
template< typename Itr, typename Compare = std::compare_three_way >
requires std::random_access_iterator< Itr > &&
         std::is_same_v< std::invoke_result_t< Compare,
                                               std::iter_value_t< Itr >,
                                               std::iter_value_t< Itr > >,
                         std::strong_ordering >
constexpr void binary(Itr begin, Itr end, Compare compare = Compare{}) {
  for (auto outerItr = std::next(begin); outerItr != end;
       outerItr      = std::next(outerItr)) {
    // Start from the previous element. (Compare backwards)
    auto innerItr = std::prev(outerItr);

    // Up to innerItr (inclusive), the range is sorted. Find the correct
    // position for outerItr.
    const auto location = impl::bSearch(begin, innerItr, outerItr, compare);

    // Save the value of outerItr.
    const auto value = *outerItr;

    // Shift the elements to make space for the new element.
    while (innerItr >= location) {
      *std::next(innerItr) = *innerItr;
      innerItr             = std::prev(innerItr);
    }

    // Insert the value of outerItr in the correct position.
    *std::next(innerItr) = value;
  }
}

} // namespace aizo::sort::insertion

#endif // UNI_AIZO_P_AIZO_SORT_INSERTION_HPP
