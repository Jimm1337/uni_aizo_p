#ifndef UNI_AIZO_P_AIZO_SORT_HEAP_HPP
#define UNI_AIZO_P_AIZO_SORT_HEAP_HPP

#include "aizo_sort_heap_impl.hpp"

/**
 * @brief Heap sort algorithms.
 */
namespace aizo::sort::heap {

/**
 * @brief Classic heap sort algorithm.
 * @category Sort
 * @note Time complexity: O(n log n).
 * @headerfile aizo_sort_heap.hpp
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
 * @details Repeatedly Builds a heap with the given compare function each time
 * with a smaller range.
 */
template< typename Itr, typename Compare = std::less<> >
requires std::random_access_iterator< Itr > &&
         std::is_same_v< std::invoke_result_t< Compare,
                                               std::iter_value_t< Itr >,
                                               std::iter_value_t< Itr > >,
                         bool >
constexpr void classic(Itr begin, Itr end, Compare compare = Compare{}) {
  impl::buildHeap(begin, end, compare);

  for (auto current = std::prev(end); current != begin;
       current      = std::prev(current)) {
    std::iter_swap(begin, current);

    impl::heapify(begin, current, compare);
  }

  std::iter_swap(begin, std::next(begin));
}

} // namespace aizo::sort::heap

#endif // UNI_AIZO_P_AIZO_SORT_HEAP_HPP
