#ifndef UNI_AIZO_P_AIZO_SORT_QUICK_IMPL_HPP
#define UNI_AIZO_P_AIZO_SORT_QUICK_IMPL_HPP

/**
 * @brief Implementation specific functionality for quick sort algorithms.
 *
 * @warning Do not use this namespace directly.
 */
namespace aizo::sort::quick::impl {

/**
 * @brief Partition the array around a pivot element.
 * @headerfile aizo_sort_quick_impl.hpp
 *
 * @tparam Itr Iterator type.
 * @tparam Compare Comparison function type.
 * @param begin Iterator to the beginning of the range.
 * @param end Iterator to the end of the range.
 * @param compare Comparison function.
 * @return Iterator to the pivot position.
 *
 * @attention Requires Itr to be at least of category RandomAccessIterator.
 * @attention Requires Compare to be a function object that returns bool.
 *
 * @details Chooses the pivot as the middle element of the array. Partitions the array around the pivot element and returns the pivot position.
 */
template< typename Itr, typename Compare = std::less<> >
requires std::random_access_iterator< Itr > &&
         std::is_same_v< std::invoke_result_t< Compare,
                                               std::iter_value_t< Itr >,
                                               std::iter_value_t< Itr > >,
                         bool >
constexpr Itr partition(Itr begin, Itr end, Compare compare = Compare{}) {
  // Choose pivot as the middle element
  const auto pivot      = std::next(begin, std::distance(begin, end) / 2);
  const auto pivotValue = *pivot;

  // Move the pivot to the end
  std::iter_swap(pivot, std::prev(end));

  // Partition the array around the pivot
  auto low  = begin;
  auto high = std::prev(end);

  while (low < high) {
    while (compare(*low, pivotValue) && low != std::prev(end)) {
      low = std::next(low);
    }
    while (!compare(*high, pivotValue) && high != begin) {
      high = std::prev(high);
    }

    if (low < high) { std::iter_swap(low, high); }
  }

  // Move the pivot to the correct position
  std::iter_swap(low, std::prev(end));

  // Return the pivot position
  return low;
}

} // namespace aizo::sort::quick::impl

#endif // UNI_AIZO_P_AIZO_SORT_QUICK_IMPL_HPP
