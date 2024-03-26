#ifndef UNI_AIZO_P_AIZO_SORT_INSERTION_IMPL_HPP
#define UNI_AIZO_P_AIZO_SORT_INSERTION_IMPL_HPP

#include <functional>
#include <iterator>

/**
 * @brief Implementation specific functionality for insertion sort algorithms.
 *
 * @warning Do not use this namespace directly.
 */
namespace aizo::sort::insertion::impl {

/**
 * @brief Binary search for insertion sort.
 * @headerfile aizo_sort_insertion_impl.hpp
 *
 * @tparam Itr Iterator type.
 * @tparam Compare Comparison function type.
 * @param lower Lower bound.
 * @param upper Upper bound.
 * @param current Current iterator.
 * @param compare Comparison function.
 * @return Iterator to the correct position.
 *
 * @attention Nodiscard.
 * @attention Requires Itr to be at least of category RandomAccessIterator.
 * @attention Requires Compare to be a function object that returns std::strong_ordering.
 *
 * @details Uses binary search to find the correct position for current element in the range [lower, upper).
 */
template< typename Itr, typename Compare >
requires std::random_access_iterator< Itr > &&
         std::is_same_v< std::invoke_result_t< Compare,
                                               std::iter_value_t< Itr >,
                                               std::iter_value_t< Itr > >,
                         std::strong_ordering >
[[nodiscard]] constexpr Itr bSearch(Itr     lower,
                                    Itr     upper,
                                    Itr     current,
                                    Compare compare = Compare{}) {
  const auto value = *current;

  while (lower <= upper) {
    // Get middle value from the range [lower, upper).
    auto mid = lower;
    std::advance(mid, std::distance(lower, upper) / 2); // O(1)
    const auto midValue = *mid;

    // Compare the middle value with the current value. If the middle value is
    // less than the current value, then the correct position is to the right of
    // the middle value. If the middle value is greater than the current value,
    // then the correct position is to the left of the middle value.
    const auto cmp = compare(midValue, value);
    if (cmp == std::strong_ordering::equal) {
      return std::next(mid);
    } else if (cmp == std::strong_ordering::less) {
      lower = std::next(mid);
    } else {
      upper = std::prev(mid);
    }
  }

  return lower;
}

} // namespace aizo::sortFunction::insertion::impl

#endif // UNI_AIZO_P_AIZO_SORT_INSERTION_IMPL_HPP
