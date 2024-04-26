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
 * @tparam EqualityComparator Equality comparison function type.
 * @param lower Iterator to the beginning of the range.
 * @param upper Iterator to the end of the range.
 * @param target Target element to find.
 * @param compare Comparison function.
 * @param equal Equality comparison function.
 * @return Iterator to the correct position.
 *
 * @attention Nodiscard.
 * @attention Requires Itr to be at least of category RandomAccessIterator.
 * @attention Requires Compare to be a function object that returns a boolean.
 * @attention Requires EqualityComparator to be a function object that returns a
 boolean.
 *
 * @details Uses binary search to find the correct position for current element
 in the range [lower, upper). Assumes that the range is sorted.
 */
template< typename Itr, typename Compare, typename EqualityComparator >
requires std::random_access_iterator< Itr > &&
         std::is_same_v< std::invoke_result_t< Compare,
                                               std::iter_value_t< Itr >,
                                               std::iter_value_t< Itr > >,
                         bool > &&
         std::is_same_v< std::invoke_result_t< EqualityComparator,
                                               std::iter_value_t< Itr >,
                                               std::iter_value_t< Itr > >,
                         bool >
[[nodiscard]] constexpr Itr bSearch(Itr                             lower,
                                    Itr                             upper,
                                    const std::iter_value_t< Itr >& target,
                                    Compare                         compare,
                                    EqualityComparator              equal) {
  while (upper > lower) {
    auto mid = std::next(lower, (std::distance(lower, upper) + 1) / 2);

    // Case found
    if (equal(*mid, target)) { return std::next(mid); }

    if (compare(*mid, target)) {
      lower = std::next(mid);
    } else {
      upper = std::prev(mid);
    }
  }

  // Case not found
  return compare(*lower, target) ? std::next(lower) : lower;
}

} // namespace aizo::sort::insertion::impl

#endif // UNI_AIZO_P_AIZO_SORT_INSERTION_IMPL_HPP
