#ifndef UNI_AIZO_P_AIZO_SORT_QUICK_HPP
#define UNI_AIZO_P_AIZO_SORT_QUICK_HPP

#include "aizo_sort_quick_impl.hpp"

/**
 * @brief Insertion sortFunction algorithms.
 */
namespace aizo::sort::quick {

/**
 * @brief Classic quick sort algorithm.
 * @category Sort
 * @note Time complexity: O(n^2).
 * @headerfile aizo_sort_quick.hpp
 *
 * @tparam Itr Iterator type.
 * @tparam Compare Comparison function type.
 * @param begin Iterator to the beginning of the range.
 * @param end Iterator to the end of the range.
 * @param compare Comparison function.
 *
 * @attention Requires Itr to be at least of category RandomAccessIterator.
 * @attention Requires Compare to be a function object that returns a boolean.
 *
 * @details Uses a recursive approach to sort the array by partitioning it around a pivot element. The pivot element is chosen as the middle element of each sub array.
 */
template< typename Itr, typename Compare = std::less<> >
requires std::random_access_iterator< Itr > &&
         std::is_same_v< std::invoke_result_t< Compare,
                                               std::iter_value_t< Itr >,
                                               std::iter_value_t< Itr > >,
                         bool >
constexpr void classic(Itr begin, Itr end, Compare compare = Compare{}) {
  if (begin < end) {
    // After partition, pivot will be in correct place
    const auto pivot = impl::partition(begin, end, compare);
    // Recursively sortFunction the left and right sub-arrays
    classic(begin, pivot, compare);
    classic(std::next(pivot), end, compare);
  }
}

} // namespace aizo::sortFunction::quick

#endif // UNI_AIZO_P_AIZO_SORT_QUICK_HPP
