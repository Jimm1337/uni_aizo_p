#ifndef UNI_AIZO_P_AIZO_MEASURE_HPP
#define UNI_AIZO_P_AIZO_MEASURE_HPP

#include "aizo_tool.hpp"
#include "aizo_sort.hpp"
#include "aizo_ds.hpp"

#include <fmt/core.h>
#include <fstream>

namespace aizo::measure {

template< typename Itr, typename Type, std::size_t... arraySizes >
requires std::output_iterator< Itr, std::string >
void quickAscending(Itr backInserter, std::size_t sampleSize = 25) {
  *backInserter++ =
    "KindOfRandom;ArraySize;SampleSize;AvgTime;MinTime;MaxTime;Unit";

  // Pure Random
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto                         arr = gen.generatePureRandom(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::quick::classic(std::begin(arr), std::end(arr));
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("PureRandom;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());

  // Sorted Ascending
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto                         arr = gen.generateSortedAscending(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::quick::classic(std::begin(arr), std::end(arr));
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("SortedAsc;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());

  // Sorted Descending
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto                         arr = gen.generateSortedDescending(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::quick::classic(std::begin(arr), std::end(arr));
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("SortedDesc;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());

  // One-Third Sorted Ascending
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto arr = gen.generateOneThirdSortedAscending(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::quick::classic(std::begin(arr), std::end(arr));
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("OneThirdAsc;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());

  // One-Third Sorted Descending
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto arr = gen.generateOneThirdSortedDescending(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::quick::classic(std::begin(arr), std::end(arr));
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("OneThirdDesc;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());

  // Two-Thirds Sorted Ascending
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto arr = gen.generateTwoThirdsSortedAscending(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::quick::classic(std::begin(arr), std::end(arr));
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("TwoThirdsAsc;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());

  // Two-Thirds Sorted Descending
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto arr = gen.generateTwoThirdsSortedDescending(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::quick::classic(std::begin(arr), std::end(arr));
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("TwoThirdsDesc;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());
}

template< typename Itr, typename Type, std::size_t... arraySizes >
requires std::output_iterator< Itr, std::string >
void quickDescending(Itr backInserter, std::size_t sampleSize = 25) {
  *backInserter++ =
    "KindOfRandom;ArraySize;SampleSize;AvgTime;MinTime;MaxTime;Unit";

  // Pure Random
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto                         arr = gen.generatePureRandom(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::quick::classic(std::begin(arr), std::end(arr), std::greater<>{});
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("PureRandom;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());

  // Sorted Ascending
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto                         arr = gen.generateSortedAscending(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::quick::classic(std::begin(arr), std::end(arr), std::greater<>{});
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("SortedAsc;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());

  // Sorted Descending
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto                         arr = gen.generateSortedDescending(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::quick::classic(std::begin(arr), std::end(arr), std::greater<>{});
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("SortedDesc;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());

  // One-Third Sorted Ascending
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto arr = gen.generateOneThirdSortedAscending(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::quick::classic(std::begin(arr), std::end(arr), std::greater<>{});
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("OneThirdAsc;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());

  // One-Third Sorted Descending
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto arr = gen.generateOneThirdSortedDescending(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::quick::classic(std::begin(arr), std::end(arr), std::greater<>{});
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("OneThirdDesc;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());

  // Two-Thirds Sorted Ascending
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto arr = gen.generateTwoThirdsSortedAscending(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::quick::classic(std::begin(arr), std::end(arr), std::greater<>{});
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("TwoThirdsAsc;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());

  // Two-Thirds Sorted Descending
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto arr = gen.generateTwoThirdsSortedDescending(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::quick::classic(std::begin(arr), std::end(arr), std::greater<>{});
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("TwoThirdsDesc;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());
}

template< typename Itr, typename Type, std::size_t... arraySizes >
requires std::output_iterator< Itr, std::string >
void heapAscending(Itr backInserter, std::size_t sampleSize = 25) {
  *backInserter++ =
    "KindOfRandom;ArraySize;SampleSize;AvgTime;MinTime;MaxTime;Unit";

  // Pure Random
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto                         arr = gen.generatePureRandom(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::heap::classic(std::begin(arr), std::end(arr));
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("PureRandom;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());

  // Sorted Ascending
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto                         arr = gen.generateSortedAscending(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::heap::classic(std::begin(arr), std::end(arr));
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("SortedAsc;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());

  // Sorted Descending
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto                         arr = gen.generateSortedDescending(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::heap::classic(std::begin(arr), std::end(arr));
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("SortedDesc;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());

  // One-Third Sorted Ascending
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto arr = gen.generateOneThirdSortedAscending(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::heap::classic(std::begin(arr), std::end(arr));
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("OneThirdAsc;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());

  // One-Third Sorted Descending
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto arr = gen.generateOneThirdSortedDescending(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::heap::classic(std::begin(arr), std::end(arr));
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("OneThirdDesc;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());

  // Two-Thirds Sorted Ascending
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto arr = gen.generateTwoThirdsSortedAscending(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::heap::classic(std::begin(arr), std::end(arr));
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("TwoThirdsAsc;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());

  // Two-Thirds Sorted Descending
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto arr = gen.generateTwoThirdsSortedDescending(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::heap::classic(std::begin(arr), std::end(arr));
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("TwoThirdsDesc;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());
}

template< typename Itr, typename Type, std::size_t... arraySizes >
requires std::output_iterator< Itr, std::string >
void heapDescending(Itr backInserter, std::size_t sampleSize = 25) {
  *backInserter++ =
    "KindOfRandom;ArraySize;SampleSize;AvgTime;MinTime;MaxTime;Unit";

  // Pure Random
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto                         arr = gen.generatePureRandom(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::heap::classic(std::begin(arr), std::end(arr), std::greater<>{});
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("PureRandom;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());

  // Sorted Ascending
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto                         arr = gen.generateSortedAscending(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::heap::classic(std::begin(arr), std::end(arr), std::greater<>{});
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("SortedAsc;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());

  // Sorted Descending
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto                         arr = gen.generateSortedDescending(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::heap::classic(std::begin(arr), std::end(arr), std::greater<>{});
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("SortedDesc;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());

  // One-Third Sorted Ascending
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto arr = gen.generateOneThirdSortedAscending(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::heap::classic(std::begin(arr), std::end(arr), std::greater<>{});
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("OneThirdAsc;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());

  // One-Third Sorted Descending
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto arr = gen.generateOneThirdSortedDescending(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::heap::classic(std::begin(arr), std::end(arr), std::greater<>{});
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("OneThirdDesc;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());

  // Two-Thirds Sorted Ascending
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto arr = gen.generateTwoThirdsSortedAscending(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::heap::classic(std::begin(arr), std::end(arr), std::greater<>{});
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("TwoThirdsAsc;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());

  // Two-Thirds Sorted Descending
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto arr = gen.generateTwoThirdsSortedDescending(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::heap::classic(std::begin(arr), std::end(arr), std::greater<>{});
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("TwoThirdsDesc;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());
}

template< typename Itr, typename Type, std::size_t... arraySizes >
requires std::output_iterator< Itr, std::string >
void insertionClassicAscending(Itr backInserter, std::size_t sampleSize = 25) {
  *backInserter++ =
    "KindOfRandom;ArraySize;SampleSize;AvgTime;MinTime;MaxTime;Unit";

  // Pure Random
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto                         arr = gen.generatePureRandom(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::insertion::classic(std::begin(arr), std::end(arr));
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("PureRandom;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());

  // Sorted Ascending
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto                         arr = gen.generateSortedAscending(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::insertion::classic(std::begin(arr), std::end(arr));
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("SortedAsc;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());

  // Sorted Descending
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto                         arr = gen.generateSortedDescending(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::insertion::classic(std::begin(arr), std::end(arr));
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("SortedDesc;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());

  // One-Third Sorted Ascending
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto arr = gen.generateOneThirdSortedAscending(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::insertion::classic(std::begin(arr), std::end(arr));
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("OneThirdAsc;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());

  // One-Third Sorted Descending
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto arr = gen.generateOneThirdSortedDescending(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::insertion::classic(std::begin(arr), std::end(arr));
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("OneThirdDesc;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());

  // Two-Thirds Sorted Ascending
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto arr = gen.generateTwoThirdsSortedAscending(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::insertion::classic(std::begin(arr), std::end(arr));
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("TwoThirdsAsc;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());

  // Two-Thirds Sorted Descending
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto arr = gen.generateTwoThirdsSortedDescending(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::insertion::classic(std::begin(arr), std::end(arr));
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("TwoThirdsDesc;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());
}

template< typename Itr, typename Type, std::size_t... arraySizes >
requires std::output_iterator< Itr, std::string >
void insertionClassicDescending(Itr backInserter, std::size_t sampleSize = 25) {
  *backInserter++ =
    "KindOfRandom;ArraySize;SampleSize;AvgTime;MinTime;MaxTime;Unit";

  // Pure Random
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto                         arr = gen.generatePureRandom(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::insertion::classic(
          std::begin(arr), std::end(arr), std::greater<>{});
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("PureRandom;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());

  // Sorted Ascending
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto                         arr = gen.generateSortedAscending(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::insertion::classic(
          std::begin(arr), std::end(arr), std::greater<>{});
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("SortedAsc;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());

  // Sorted Descending
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto                         arr = gen.generateSortedDescending(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::insertion::classic(
          std::begin(arr), std::end(arr), std::greater<>{});
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("SortedDesc;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());

  // One-Third Sorted Ascending
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto arr = gen.generateOneThirdSortedAscending(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::insertion::classic(
          std::begin(arr), std::end(arr), std::greater<>{});
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("OneThirdAsc;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());

  // One-Third Sorted Descending
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto arr = gen.generateOneThirdSortedDescending(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::insertion::classic(
          std::begin(arr), std::end(arr), std::greater<>{});
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("OneThirdDesc;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());

  // Two-Thirds Sorted Ascending
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto arr = gen.generateTwoThirdsSortedAscending(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::insertion::classic(
          std::begin(arr), std::end(arr), std::greater<>{});
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("TwoThirdsAsc;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());

  // Two-Thirds Sorted Descending
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto arr = gen.generateTwoThirdsSortedDescending(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::insertion::classic(
          std::begin(arr), std::end(arr), std::greater<>{});
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("TwoThirdsDesc;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());
}

template< typename Itr, typename Type, std::size_t... arraySizes >
requires std::output_iterator< Itr, std::string >
void insertionBinaryAscending(Itr backInserter, std::size_t sampleSize = 25) {
  *backInserter++ =
    "KindOfRandom;ArraySize;SampleSize;AvgTime;MinTime;MaxTime;Unit";

  // Pure Random
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto                         arr = gen.generatePureRandom(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::insertion::binary(std::begin(arr), std::end(arr));
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("PureRandom;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());

  // Sorted Ascending
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto                         arr = gen.generateSortedAscending(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::insertion::binary(std::begin(arr), std::end(arr));
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("SortedAsc;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());

  // Sorted Descending
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto                         arr = gen.generateSortedDescending(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::insertion::binary(std::begin(arr), std::end(arr));
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("SortedDesc;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());

  // One-Third Sorted Ascending
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto arr = gen.generateOneThirdSortedAscending(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::insertion::binary(std::begin(arr), std::end(arr));
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("OneThirdAsc;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());

  // One-Third Sorted Descending
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto arr = gen.generateOneThirdSortedDescending(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::insertion::binary(std::begin(arr), std::end(arr));
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("OneThirdDesc;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());

  // Two-Thirds Sorted Ascending
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto arr = gen.generateTwoThirdsSortedAscending(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::insertion::binary(std::begin(arr), std::end(arr));
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("TwoThirdsAsc;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());

  // Two-Thirds Sorted Descending
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto arr = gen.generateTwoThirdsSortedDescending(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::insertion::binary(std::begin(arr), std::end(arr));
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("TwoThirdsDesc;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());
}

template< typename Itr, typename Type, std::size_t... arraySizes >
requires std::output_iterator< Itr, std::string >
void insertionBinaryDescending(Itr backInserter, std::size_t sampleSize = 25) {
  *backInserter++ =
    "KindOfRandom;ArraySize;SampleSize;AvgTime;MinTime;MaxTime;Unit";

  // Pure Random
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto                         arr = gen.generatePureRandom(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::insertion::binary(
          std::begin(arr), std::end(arr), std::greater<>{});
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("PureRandom;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());

  // Sorted Ascending
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto                         arr = gen.generateSortedAscending(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::insertion::binary(
          std::begin(arr), std::end(arr), std::greater<>{});
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("SortedAsc;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());

  // Sorted Descending
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto                         arr = gen.generateSortedDescending(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::insertion::binary(
          std::begin(arr), std::end(arr), std::greater<>{});
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("SortedDesc;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());

  // One-Third Sorted Ascending
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto arr = gen.generateOneThirdSortedAscending(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::insertion::binary(
          std::begin(arr), std::end(arr), std::greater<>{});
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("OneThirdAsc;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());

  // One-Third Sorted Descending
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto arr = gen.generateOneThirdSortedDescending(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::insertion::binary(
          std::begin(arr), std::end(arr), std::greater<>{});
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("OneThirdDesc;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());

  // Two-Thirds Sorted Ascending
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto arr = gen.generateTwoThirdsSortedAscending(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::insertion::binary(
          std::begin(arr), std::end(arr), std::greater<>{});
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("TwoThirdsAsc;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());

  // Two-Thirds Sorted Descending
  (..., [&]() {
    std::size_t      samples   = 0;
    auto             minTime   = std::numeric_limits< double >::max();
    auto             maxTime   = std::numeric_limits< double >::min();
    double           totalTime = 0;
    std::string_view unit{};

    for (std::size_t i = 0; i < sampleSize; ++i) {
      tool::ArrayGenerator< Type > gen{ arraySizes };
      auto arr = gen.generateTwoThirdsSortedDescending(0, 1000);

      tool::Timer timedSort{ [&arr] {
        sort::insertion::binary(
          std::begin(arr), std::end(arr), std::greater<>{});
      } };

      timedSort();

      const auto durationStr = timedSort.getDurationStr();
      const auto time        = durationStr.first;
      unit                   = durationStr.second;
      ++samples;
      minTime = std::min(minTime, time);
      maxTime = std::max(maxTime, time);
      totalTime += time;
    }

    const auto avgTime = totalTime / static_cast< double >(samples);

    *backInserter++ = fmt::format("TwoThirdsDesc;{};{};{:.4f};{:.4f};{:.4f};{}",
                                  arraySizes,
                                  samples,
                                  avgTime,
                                  minTime,
                                  maxTime,
                                  unit);
  }());
}

void allToFiles(std::size_t sampleSize = 25) {
  ds::DynamicArray< std::string > results{};
  std::ofstream              file{};
  using Inserter = decltype(std::back_inserter(results));

  // Quick Sort
  results.emplace_back("Results: int, Ascending");
  quickAscending< Inserter, int, 1000, 2000, 3000, 4000, 5000, 6000, 7000 >(
    std::back_inserter(results), sampleSize);
  results.emplace_back("\nResults: float, Ascending");
  quickAscending< Inserter, float, 1000, 2000, 3000, 4000, 5000, 6000, 7000 >(
    std::back_inserter(results), sampleSize);
  results.emplace_back("\nResults: int, Descending");
  quickDescending< Inserter, int, 1000, 2000, 3000, 4000, 5000, 6000, 7000 >(
    std::back_inserter(results), sampleSize);
  results.emplace_back("\nResults: float, Descending");
  quickDescending< Inserter, float, 1000, 2000, 3000, 4000, 5000, 6000, 7000 >(
    std::back_inserter(results), sampleSize);
  file.open("results_quicksort.csv");
  for (const auto& line : results) { file << line << '\n'; }
  file.close();
  results.clear();

  // Heap Sort
  results.emplace_back("Results: int, Ascending");
  heapAscending< Inserter, int, 500, 1000, 1500, 2000, 2500, 3000, 3500 >(
    std::back_inserter(results), sampleSize);
  results.emplace_back("\nResults: float, Ascending");
  heapAscending< Inserter, float, 500, 1000, 1500, 2000, 2500, 3000, 3500 >(
    std::back_inserter(results), sampleSize);
  results.emplace_back("\nResults: int, Descending");
  heapDescending< Inserter, int, 500, 1000, 1500, 2000, 2500, 3000, 3500 >(
    std::back_inserter(results), sampleSize);
  results.emplace_back("\nResults: float, Descending");
  heapDescending< Inserter, float, 500, 1000, 1500, 2000, 2500, 3000, 3500 >(
    std::back_inserter(results), sampleSize);
  file.open("results_heapsort.csv");
  for (const auto& line : results) { file << line << '\n'; }
  file.close();
  results.clear();

  // Classic Insertion Sort
  results.emplace_back("Results: int, Ascending");
  insertionClassicAscending< Inserter,
                             int,
                             500,
                             1000,
                             1500,
                             2000,
                             2500,
                             3000,
                             3500 >(std::back_inserter(results), sampleSize);
  results.emplace_back("\nResults: float, Ascending");
  insertionClassicAscending< Inserter,
                             float,
                             500,
                             1000,
                             1500,
                             2000,
                             2500,
                             3000,
                             3500 >(std::back_inserter(results), sampleSize);
  results.emplace_back("\nResults: int, Descending");
  insertionClassicDescending< Inserter,
                              int,
                              500,
                              1000,
                              1500,
                              2000,
                              2500,
                              3000,
                              3500 >(std::back_inserter(results), sampleSize);
  results.emplace_back("\nResults: float, Descending");
  insertionClassicDescending< Inserter,
                              float,
                              500,
                              1000,
                              1500,
                              2000,
                              2500,
                              3000,
                              3500 >(std::back_inserter(results), sampleSize);
  file.open("results_insertionsort_classic.csv");
  for (const auto& line : results) { file << line << '\n'; }
  file.close();
  results.clear();

  // Binary Insertion Sort
  results.emplace_back("Results: int, Ascending");
  insertionBinaryAscending< Inserter,
                            int,
                            500,
                            1000,
                            1500,
                            2000,
                            2500,
                            3000,
                            3500 >(std::back_inserter(results), sampleSize);
  results.emplace_back("\nResults: float, Ascending");
  insertionBinaryAscending< Inserter,
                            float,
                            500,
                            1000,
                            1500,
                            2000,
                            2500,
                            3000,
                            3500 >(std::back_inserter(results), sampleSize);
  results.emplace_back("\nResults: int, Descending");
  insertionBinaryDescending< Inserter,
                             int,
                             500,
                             1000,
                             1500,
                             2000,
                             2500,
                             3000,
                             3500 >(std::back_inserter(results), sampleSize);
  results.emplace_back("\nResults: float, Descending");
  insertionBinaryDescending< Inserter,
                             float,
                             500,
                             1000,
                             1500,
                             2000,
                             2500,
                             3000,
                             3500 >(std::back_inserter(results), sampleSize);
  file.open("results_insertionsort_binary.csv");
  for (const auto& line : results) { file << line << '\n'; }
}

} // namespace aizo::measure

#endif // UNI_AIZO_P_AIZO_MEASURE_HPP
