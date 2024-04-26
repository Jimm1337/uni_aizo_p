#ifndef UNI_AIZO_P_AIZO_TOOL_ARRAYREADER_HPP
#define UNI_AIZO_P_AIZO_TOOL_ARRAYREADER_HPP

#include <iterator>

namespace aizo::tool {

/**
 * @brief Reader for reading array data from an input stream.
 * @headerfile aizo_tool_arrayreader.hpp
 *
 * @warning Specialized for data of format: size data1 data2 ... dataN.
 *
 * @tparam Contained type of the data to be read.
 * @tparam Itr type of the input iterator.
 *
 * @attention Requires Itr to be at least of category InputIterator.
 */
template< typename Contained = int,
          typename Itr       = std::istream_iterator< Contained > >
requires std::input_iterator< Itr >
class ArrayReader {
public:
  /**
   * @brief Construct a new Reader object on the given input iterator.
   * @param source Input iterator to read from.
   */
  explicit ArrayReader(Itr source): source{ source }, valid{ true } {
  }

  /**
   * @brief Read data from the input iterator.
   * @warning Single pass per Itr only.
   * @note Nodiscard.
   * @throws std::runtime_error if the reader is reused.
   * @return Read data with size info.
   */
  [[nodiscard]] std::pair< ds::DynamicArray< Contained >, std::size_t > read() {
    // Single pass only
    if (!valid) {
      throw std::runtime_error{ "Reader doesn't have valid source." };
    }

    // Read to
    ds::DynamicArray< Contained > data{};
    std::size_t              size{};

    // Read size
    size = static_cast<std::size_t>(*source);
    std::advance(source, 1);

    // Read data
    data.resize(size);
    for (auto& element : data) {
      element = *source;
      std::advance(source, 1);
    }

    // Invalidate reader, to avoid reuse of single-use Iterator
    valid = false;

    // Return read data with size info
    return { std::move(data), size };
  }

  /**
   * @brief Check if the reader is valid.
   * @note Nodiscard.
   * @return True if the reader is valid, false otherwise.
   */
  [[nodiscard]] bool isValid() const {
    return valid;
  }

  /**
   * @brief Get the source iterator.
   * @note Nodiscard.
   * @return Source iterator.
   */
  [[nodiscard]] Itr getSource() const {
    return source;
  }

  /**
   * @brief Set the source iterator.
   * @param source Source iterator.
   */
  void setSource(Itr newSource) {
    source = newSource;
    valid  = true;
  }

private:
  Itr  source{};
  bool valid{ false };
};

} // namespace aizo::tool

#endif // UNI_AIZO_P_AIZO_TOOL_ARRAYREADER_HPP
