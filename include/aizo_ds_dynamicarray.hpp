#ifndef UNI_AIZO_P_AIZO_DS_DYNAMICARRAY_HPP
#define UNI_AIZO_P_AIZO_DS_DYNAMICARRAY_HPP

#include <algorithm>
#include <cstddef>
#include <gsl/gsl>

namespace aizo::ds {

template< typename T >
class DynamicArray {
public:
  class Iterator {
  public:
    using iterator_category [[maybe_unused]] = std::contiguous_iterator_tag;
    using value_type                         = T;
    using difference_type                    = std::ptrdiff_t;
    using pointer                            = T*;
    using reference                          = T&;

    constexpr Iterator() = default;

    constexpr explicit Iterator(pointer ptr) noexcept: m_ptr{ ptr } { // NOLINT
    }

    [[nodiscard]] constexpr reference operator*() const noexcept {
      return *m_ptr;
    }

    [[nodiscard]] constexpr pointer operator->() const noexcept {
      return m_ptr;
    }

    constexpr Iterator& operator++() noexcept {
      ++m_ptr;
      return *this;
    }

    constexpr Iterator operator++(int) noexcept {
      Iterator tmp = *this;
      ++(*this);
      return tmp;
    }

    constexpr Iterator& operator--() noexcept {
      --m_ptr;
      return *this;
    }

    constexpr Iterator operator--(int) noexcept {
      Iterator tmp = *this;
      --(*this);
      return tmp;
    }

    constexpr Iterator& operator+=(difference_type n) noexcept {
      m_ptr += n;
      return *this;
    }

    [[nodiscard]] constexpr Iterator operator+(
      difference_type n) const noexcept {
      return Iterator{ m_ptr + n };
    }

    [[nodiscard]] friend constexpr Iterator operator+(
      difference_type n, const Iterator& itr) noexcept {
      return Iterator{ itr.m_ptr + n };
    }

    constexpr Iterator& operator-=(difference_type n) noexcept {
      m_ptr -= n;
      return *this;
    }

    [[nodiscard]] constexpr Iterator operator-(
      difference_type n) const noexcept {
      return Iterator{ m_ptr - n };
    }

    [[nodiscard]] constexpr difference_type operator-(
      const Iterator& rhs) const noexcept {
      return m_ptr - rhs.m_ptr;
    }

    [[nodiscard]] constexpr reference operator[](
      difference_type n) const noexcept {
      return m_ptr[n];
    }

    [[nodiscard]] constexpr auto operator<=>(Iterator const&) const = default;

  private:
    pointer m_ptr{};
  };

  class ConstIterator {
  public:
    using iterator_category [[maybe_unused]] = std::contiguous_iterator_tag;
    using value_type                         = T;
    using difference_type                    = std::ptrdiff_t;
    using pointer                            = const T*;
    using reference                          = const T&;

    constexpr ConstIterator() = default;

    constexpr explicit ConstIterator(pointer ptr) noexcept:
      m_ptr{ ptr } { // NOLINT
    }

    [[nodiscard]] constexpr reference operator*() const noexcept {
      return *m_ptr;
    }

    [[nodiscard]] constexpr pointer operator->() const noexcept {
      return m_ptr;
    }

    constexpr ConstIterator& operator++() noexcept {
      ++m_ptr;
      return *this;
    }

    constexpr ConstIterator operator++(int) noexcept {
      ConstIterator tmp = *this;
      ++(*this);
      return tmp;
    }

    constexpr ConstIterator& operator--() noexcept {
      --m_ptr;
      return *this;
    }

    constexpr ConstIterator operator--(int) noexcept {
      ConstIterator tmp = *this;
      --(*this);
      return tmp;
    }

    constexpr ConstIterator& operator+=(difference_type n) noexcept {
      m_ptr += n;
      return *this;
    }

    [[nodiscard]] constexpr ConstIterator operator+(
      difference_type n) const noexcept {
      return ConstIterator{ m_ptr + n };
    }

    [[nodiscard]] friend constexpr ConstIterator operator+(
      difference_type n, const ConstIterator& itr) noexcept {
      return ConstIterator{ itr.m_ptr + n };
    }

    constexpr ConstIterator& operator-=(difference_type n) noexcept {
      m_ptr -= n;
      return *this;
    }

    [[nodiscard]] constexpr ConstIterator operator-(
      difference_type n) const noexcept {
      return ConstIterator{ m_ptr - n };
    }

    [[nodiscard]] constexpr difference_type operator-(
      const ConstIterator& rhs) const noexcept {
      return m_ptr - rhs.m_ptr;
    }

    [[nodiscard]] constexpr reference operator[](
      difference_type n) const noexcept {
      return m_ptr[n];
    }

    [[nodiscard]] constexpr auto operator<=>(ConstIterator const&) const =
      default;

  private:
    pointer m_ptr{};
  };

  class ReverseIterator {
  public:
    using iterator_category [[maybe_unused]] = std::contiguous_iterator_tag;
    using value_type                         = T;
    using difference_type                    = std::ptrdiff_t;
    using pointer                            = T*;
    using reference                          = T&;

    constexpr ReverseIterator() = default;

    constexpr explicit ReverseIterator(pointer ptr) noexcept:
      m_ptr{ ptr } { // NOLINT
    }

    [[nodiscard]] constexpr reference operator*() const noexcept {
      return *m_ptr;
    }

    [[nodiscard]] constexpr pointer operator->() const noexcept {
      return m_ptr;
    }

    constexpr ReverseIterator& operator++() noexcept {
      --m_ptr;
      return *this;
    }

    constexpr ReverseIterator operator++(int) noexcept {
      ReverseIterator tmp = *this;
      --(*this);
      return tmp;
    }

    constexpr ReverseIterator& operator--() noexcept {
      ++m_ptr;
      return *this;
    }

    constexpr ReverseIterator operator--(int) noexcept {
      ReverseIterator tmp = *this;
      ++(*this);
      return tmp;
    }

    constexpr ReverseIterator& operator+=(difference_type n) noexcept {
      m_ptr -= n;
      return *this;
    }

    [[nodiscard]] constexpr ReverseIterator operator+(
      difference_type n) const noexcept {
      return ReverseIterator{ m_ptr - n };
    }

    [[nodiscard]] friend constexpr ReverseIterator operator+(
      difference_type n, const ReverseIterator& itr) noexcept {
      return ReverseIterator{ itr.m_ptr - n };
    }

    constexpr ReverseIterator& operator-=(difference_type n) noexcept {
      m_ptr += n;
      return *this;
    }

    [[nodiscard]] constexpr ReverseIterator operator-(
      difference_type n) const noexcept {
      return ReverseIterator{ m_ptr + n };
    }

    [[nodiscard]] constexpr difference_type operator-(
      const ReverseIterator& rhs) const noexcept {
      return m_ptr - rhs.m_ptr;
    }

    [[nodiscard]] constexpr reference operator[](
      difference_type n) const noexcept {
      return m_ptr[-n];
    }

    [[nodiscard]] constexpr auto operator<=>(ReverseIterator const&) const =
      default;

  private:
    pointer m_ptr{};
  };

  class ConstReverseIterator {
  public:
    using iterator_category [[maybe_unused]] = std::contiguous_iterator_tag;
    using value_type                         = T;
    using difference_type                    = std::ptrdiff_t;
    using pointer                            = const T*;
    using reference                          = const T&;

    constexpr ConstReverseIterator() = default;

    constexpr explicit ConstReverseIterator(pointer ptr) noexcept:
      m_ptr{ ptr } { // NOLINT
    }

    [[nodiscard]] constexpr reference operator*() const noexcept {
      return *m_ptr;
    }

    [[nodiscard]] constexpr pointer operator->() const noexcept {
      return m_ptr;
    }

    constexpr ConstReverseIterator& operator++() noexcept {
      --m_ptr;
      return *this;
    }

    constexpr ConstReverseIterator operator++(int) noexcept {
      ConstReverseIterator tmp = *this;
      --(*this);
      return tmp;
    }

    constexpr ConstReverseIterator& operator--() noexcept {
      ++m_ptr;
      return *this;
    }

    constexpr ConstReverseIterator operator--(int) noexcept {
      ConstReverseIterator tmp = *this;
      ++(*this);
      return tmp;
    }

    constexpr ConstReverseIterator& operator+=(difference_type n) noexcept {
      m_ptr -= n;
      return *this;
    }

    [[nodiscard]] constexpr ConstReverseIterator operator+(
      difference_type n) const noexcept {
      return ConstReverseIterator{ m_ptr - n };
    }

    [[nodiscard]] friend constexpr ConstReverseIterator operator+(
      difference_type n, const ConstReverseIterator& itr) noexcept {
      return ConstReverseIterator{ itr.m_ptr - n };
    }

    constexpr ConstReverseIterator& operator-=(difference_type n) noexcept {
      m_ptr += n;
      return *this;
    }

    [[nodiscard]] constexpr ConstReverseIterator operator-(
      difference_type n) const noexcept {
      return ConstReverseIterator{ m_ptr + n };
    }

    [[nodiscard]] constexpr difference_type operator-(
      const ConstReverseIterator& rhs) const noexcept {
      return m_ptr - rhs.m_ptr;
    }

    [[nodiscard]] constexpr reference operator[](
      difference_type n) const noexcept {
      return m_ptr[-n];
    }

    [[nodiscard]] constexpr auto operator<=>(
      ConstReverseIterator const&) const = default;

  private:
    pointer m_ptr{};
  };

  using value_type             = T;
  using reference              = T&;
  using const_reference        = const T&;
  using pointer                = T*;
  using const_pointer          = const T*;
  using size_type              = std::size_t;
  using difference_type        = std::ptrdiff_t;
  using iterator               = Iterator;
  using const_iterator         = ConstIterator;
  using reverse_iterator       = ReverseIterator;
  using const_reverse_iterator = ConstReverseIterator;
  using allocator_type         = std::allocator< T >;

  constexpr DynamicArray() = default;

  constexpr explicit DynamicArray(size_type size):
    m_data{ new T[size] }, m_size{ size }, m_capacity{ size } { // NOLINT
  }

  constexpr DynamicArray(size_type size, const_reference value):
    m_data{ new T[size] }, m_size{ size }, m_capacity{ size } {
    for (difference_type i = 0; i < size; ++i) { m_data[i] = value; }
  }

  template< typename... ValueType >
  requires(sizeof...(ValueType) > 0) &&
            (std::is_same_v< std::remove_cvref_t< ValueType >, T > && ...)
  constexpr explicit DynamicArray(ValueType&&... values):
    m_data{ new T[sizeof...(values)] },
    m_size{ sizeof...(values) },
    m_capacity{ sizeof...(values) } {
    difference_type idx = 0;
    ((m_data[idx++] = std::forward< ValueType >(values)), ...);
  }

  constexpr DynamicArray(const DynamicArray< T >& other):
    m_data{ new T[other.m_size] },
    m_size{ other.m_size },
    m_capacity{ other.m_size } {
    for (difference_type i = 0; i < m_size; ++i) {
      m_data[i] = other.m_data[i];
    }
  }

  constexpr DynamicArray(DynamicArray< T >&& other) noexcept:
    m_data{ other.m_data },
    m_size{ other.m_size },
    m_capacity{ other.m_capacity } {
    other.m_data     = nullptr;
    other.m_size     = 0;
    other.m_capacity = 0;
  }

  constexpr ~DynamicArray() noexcept {
    delete[] m_data;
  }

  constexpr DynamicArray& operator=(const DynamicArray< T >& other) {
    if (this != &other) {
      delete[] m_data;
      m_data     = new T[other.m_size];
      m_size     = other.m_size;
      m_capacity = other.m_size;
      for (difference_type i = 0; i < m_size; ++i) {
        m_data[i] = other.m_data[i];
      }
    }
    return *this;
  }

  constexpr DynamicArray& operator=(DynamicArray< T >&& other) noexcept {
    if (this != &other) {
      delete[] m_data;
      m_data           = other.m_data; // NOLINT
      m_size           = other.m_size;
      m_capacity       = other.m_capacity;
      other.m_data     = nullptr;
      other.m_size     = 0;
      other.m_capacity = 0;
    }
    return *this;
  }

  [[nodiscard]] constexpr reference operator[](difference_type index) noexcept {
    return m_data[index];
  }

  [[nodiscard]] constexpr const_reference operator[](
    difference_type index) const noexcept {
    return m_data[index];
  }

  [[nodiscard]] constexpr reference at(size_type index) {
    if (index >= m_size) { throw std::out_of_range{ "Index out of range" }; }
    return m_data[index];
  }

  [[nodiscard]] constexpr const_reference at(size_type index) const {
    if (index >= m_size) { throw std::out_of_range{ "Index out of range" }; }
    return m_data[index];
  }

  [[nodiscard]] constexpr reference front() noexcept {
    return m_data[0];
  }

  [[nodiscard]] constexpr const_reference front() const noexcept {
    return m_data[0];
  }

  [[nodiscard]] constexpr reference back() noexcept {
    return m_data[m_size - 1];
  }

  [[nodiscard]] constexpr const_reference back() const noexcept {
    return m_data[m_size - 1];
  }

  [[nodiscard]] constexpr pointer data() noexcept {
    return m_data; // NOLINT
  }

  [[nodiscard]] constexpr const_pointer data() const noexcept {
    return m_data; // NOLINT
  }

  [[nodiscard]] constexpr size_type size() const noexcept {
    return m_size;
  }

  [[nodiscard]] constexpr size_type capacity() const noexcept {
    return m_capacity;
  }

  [[nodiscard]] constexpr bool empty() const noexcept {
    return m_size == 0;
  }

  constexpr void clear() noexcept {
    m_size = 0;
  }

  constexpr void reserve(std::size_t new_capacity) {
    if (new_capacity > m_capacity) {
      m_capacity                     = new_capacity;
      gsl::owner< pointer > new_data = new T[m_capacity]; // NOLINT

      for (difference_type i = 0; i < m_size; ++i) { new_data[i] = m_data[i]; }

      delete[] m_data;

      m_data = new_data;
    }
  }

  constexpr void resize(std::size_t new_size, const T& value = {}) {
    if (new_size > m_capacity) {
      m_capacity                     = new_size;
      gsl::owner< pointer > new_data = new T[m_capacity]; // NOLINT

      for (difference_type i = 0; i < m_size; ++i) { new_data[i] = m_data[i]; }

      delete[] m_data;

      m_data = new_data;
      m_size = new_size;
    } else if (new_size <= m_size) {
      m_size = new_size;
    } else {
      for (std::size_t i = m_size; i < new_size; ++i) { m_data[i] = value; }
      m_size = new_size;
    }
  }

  constexpr void pop_back() noexcept {
    if (m_size > 0) { --m_size; }
  }

  template< typename... Contained >
  requires(std::is_same_v< std::remove_cvref_t< Contained >, T > && ...)
  constexpr void push_back(Contained&&... values) {
    if (m_size + sizeof...(values) > m_capacity) {
      m_capacity                     = m_capacity == 0 ? 1 : m_capacity * 2;
      gsl::owner< pointer > new_data = new T[m_capacity]; // NOLINT

      m_capacity = std::max(m_capacity, m_size + sizeof...(values));

      for (difference_type i = 0; i < m_size; ++i) { new_data[i] = m_data[i]; }

      delete[] m_data;

      m_data = new_data;
    }

    ((m_data[m_size++] = std::forward< Contained >(values)), ...);
  }

  template< typename... Contained >
  requires(std::is_same_v< std::remove_cvref_t< Contained >, T > && ...)
  constexpr void push_front(Contained&&... values) {
    if (m_size + sizeof...(values) > m_capacity) {
      m_capacity = m_capacity == 0 ? 1 : m_capacity * 2;
      if (m_capacity < sizeof...(values)) { m_capacity += sizeof...(values); }

      m_capacity = std::max(m_capacity, m_size + sizeof...(values));

      gsl::owner< pointer > new_data = new T[m_capacity]; // NOLINT

      for (difference_type i = sizeof...(values); i < m_size; ++i) {
        new_data[i] = m_data[i - sizeof...(values)];
      }

      delete[] m_data;

      m_data = new_data;
    }

    std::size_t idx = 0;
    ((m_data[idx++] = std::forward< Contained >(values)), ...);

    m_size += sizeof...(values);
  }

  template< typename... Args >
  requires(std::is_constructible_v< T, Args... >)
  constexpr void emplace_back(Args&&... args) {
    if (m_size + 1 > m_capacity) {
      m_capacity                     = m_capacity == 0 ? 1 : m_capacity * 2;
      gsl::owner< pointer > new_data = new T[m_capacity]; // NOLINT

      for (difference_type i = 0; i < m_size; ++i) { new_data[i] = m_data[i]; }

      delete[] m_data;

      m_data = new_data;
    }

    m_data[m_size++] = T{ std::forward< Args >(args)... };
  }

  template< typename... Args >
  requires(std::is_constructible_v< T, Args... >)
  constexpr void emplace_front(Args&&... args) {
    if (m_size + 1 > m_capacity) {
      m_capacity                     = m_capacity == 0 ? 1 : m_capacity * 2;
      gsl::owner< pointer > new_data = new T[m_capacity]; // NOLINT

      for (difference_type i = 1; i < m_size; ++i) {
        new_data[i] = m_data[i - 1];
      }

      delete[] m_data;

      m_data = new_data;
    }

    m_data[0] = T{ std::forward< Args >(args)... };

    ++m_size;
  }

  [[nodiscard]] constexpr iterator begin() noexcept {
    return iterator{ m_data };
  }

  [[nodiscard]] constexpr const_iterator begin() const noexcept {
    return const_iterator{ m_data };
  }

  [[nodiscard]] constexpr const_iterator cbegin() const noexcept {
    return const_iterator{ m_data };
  }

  [[nodiscard]] constexpr iterator end() noexcept {
    return iterator{ m_data + m_size };
  }

  [[nodiscard]] constexpr const_iterator end() const noexcept {
    return const_iterator{ m_data + m_size };
  }

  [[nodiscard]] constexpr const_iterator cend() const noexcept {
    return const_iterator{ m_data + m_size };
  }

  [[nodiscard]] constexpr reverse_iterator rbegin() noexcept {
    return reverse_iterator{ m_data + m_size - 1 };
  }

  [[nodiscard]] constexpr const_reverse_iterator rbegin() const noexcept {
    return const_reverse_iterator{ m_data + m_size - 1 };
  }

  [[nodiscard]] constexpr const_reverse_iterator crbegin() const noexcept {
    return const_reverse_iterator{ m_data + m_size - 1 };
  }

  [[nodiscard]] constexpr reverse_iterator rend() noexcept {
    return reverse_iterator{ m_data - 1 };
  }

  [[nodiscard]] constexpr const_reverse_iterator rend() const noexcept {
    return const_reverse_iterator{ m_data - 1 };
  }

  [[nodiscard]] constexpr const_reverse_iterator crend() const noexcept {
    return const_reverse_iterator{ m_data - 1 };
  }

private:
  gsl::owner< pointer > m_data{};
  size_type             m_size{};
  size_type             m_capacity{};
};

} // namespace aizo::ds

template< typename T, typename U >
[[nodiscard]] constexpr bool operator==(
  const aizo::ds::DynamicArray< T >& lhs,
  const aizo::ds::DynamicArray< U >& rhs) {
  if constexpr (!std::is_same_v< T, U >) { return false; }

  if (lhs.size() != rhs.size()) { return false; }

  for (std::size_t i = 0; i < lhs.size(); ++i) {
    if (lhs[i] != rhs[i]) { return false; }
  }

  return true;
}

#endif // UNI_AIZO_P_AIZO_DS_DYNAMICARRAY_HPP
