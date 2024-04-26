#ifndef UNI_AIZO_P_AIZO_SORT_HEAP_IMPL_HPP
#define UNI_AIZO_P_AIZO_SORT_HEAP_IMPL_HPP

/**
 * @brief Implementation specific functionality for heap sortFunction
 * algorithms.
 *
 * @warning Do not use this namespace directly.
 */
namespace aizo::sort::heap::impl {

/**
 * @brief Heap building for heap sortFunction
 * @headerfile aizo_sort_heap_impl.hpp
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
 * @details Iteratively builds a heap with the given compare function.
 */
template< typename Itr, typename Compare = std::less<> >
requires std::random_access_iterator< Itr > &&
         std::is_same_v< std::invoke_result_t< Compare,
                                               std::iter_value_t< Itr >,
                                               std::iter_value_t< Itr > >,
                         bool >
constexpr void buildHeap(Itr begin, Itr end, Compare compare = Compare{}) {
  for (auto current = std::next(begin); current != end;
       current      = std::next(current)) {
    auto parent = std::next(begin, (std::distance(begin, current) - 1) / 2);

    // Bubble up the current element until it is in the correct position.
    auto currentInner = current;
    while (compare(*parent, *currentInner)) {
      std::iter_swap(currentInner, parent);
      currentInner = parent;
      parent = std::next(begin, (std::distance(begin, currentInner) - 1) / 2);
    }
  }
}

/**
 * @brief Heapifying for heapsort function
 * @headerfile aizo_sort_heap_impl.hpp
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
 * @details Iteratively heapifies the range with the given compare function. Assumes that the range is already a heap except for the first element.
 */
template< typename Itr, typename Compare = std::less<> >
requires std::random_access_iterator< Itr > &&
         std::is_same_v< std::invoke_result_t< Compare,
                                               std::iter_value_t< Itr >,
                                               std::iter_value_t< Itr > >,
                         bool >
constexpr void heapify(Itr begin, Itr end, Compare compare = Compare{}) {
  auto parent = begin;
  auto left   = std::next(begin);
  auto right  = std::next(left);

  while (parent < end) {
    auto mostQualified = parent;

    if (compare(*mostQualified, *left)) { mostQualified = left; }

    if (right < end && compare(*mostQualified, *right)) {
      mostQualified = right;
    }

    // If the parent is the most qualified, then the heap is already in order.
    if (mostQualified == parent) { return; }

    // Otherwise, swap the parent with the most qualified child.
    std::iter_swap(parent, mostQualified);

    // Update the parent iterator.
    parent = mostQualified;

    // If nextLeftIdx is out of bounds, then the heap is already in order.
    auto nextLeftIdx = 2 * std::distance(begin, parent) + 1;
    if (nextLeftIdx >= std::distance(begin, end)) { return; }

    // Update the left and right iterators.
    left  = std::next(begin, 2 * std::distance(begin, parent) + 1);
    right = std::next(left);
  }
}

} // namespace aizo::sort::heap::impl

#endif // UNI_AIZO_P_AIZO_SORT_HEAP_IMPL_HPP
