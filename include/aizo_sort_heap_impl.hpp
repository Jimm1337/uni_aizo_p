#ifndef UNI_AIZO_P_AIZO_SORT_HEAP_IMPL_HPP
#define UNI_AIZO_P_AIZO_SORT_HEAP_IMPL_HPP

/**
 * @brief Implementation specific functionality for heap sortFunction algorithms.
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
  for (auto child = std::next(begin); child != end; child = std::next(child)) {
    auto parent    = begin;
    auto nextChild = child;

    // While child satisfies the compare function with its parent. Swap them
    // until it doesn't.
    while (compare(*nextChild, *parent)) {
      std::iter_swap(nextChild, parent);

      // Calculate next parent index to check if we reached root.
      const auto parentIdx     = std::distance(begin, parent);
      const auto nextParentIdx = (parentIdx - 1) / 2;

      if (nextParentIdx <= 0) { break; }

      // if not then nextChild will be current parent and its parent will be the
      // key with index calculated above.
      nextChild = parent;
      parent    = std::next(begin, nextParentIdx);
    }
  }
}

} // namespace aizo::sortFunction::heap::impl

#endif // UNI_AIZO_P_AIZO_SORT_HEAP_IMPL_HPP
