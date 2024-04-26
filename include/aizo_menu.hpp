#ifndef UNI_AIZO_P_AIZO_MENU_HPP
#define UNI_AIZO_P_AIZO_MENU_HPP

#include <scn/scan.h>
#include <fmt/format.h>
#include <cstddef>
#include "aizo_ds_dynamicarray.hpp"
#include "aizo_tool_arrayreader.hpp"
#include "aizo_tool_arraygenerator.hpp"
#include "aizo_sort_heap.hpp"
#include "aizo_sort_insertion.hpp"
#include "aizo_measure.hpp"
#include <fstream>

namespace aizo {

/**
 * @brief Menu for the library.
 */
class Menu {
public:
  enum class DataType : std::int_fast8_t {
    INT,
    FLOAT,
    NONE
  };

  /**
   * @brief Show the main menu.
   */
  void showMainMenu() {
    fmt::println("--- Main Menu ---");
    fmt::println("1. Data: Read from file");
    fmt::println("2. Data: Generate");
    fmt::println("3. Data: Show");
    fmt::println("4. Sort: Quick sort");
    fmt::println("5. Sort: Heap sort");
    fmt::println("6. Sort: Classic insertion sort");
    fmt::println("7. Sort: Binary insertion sort");
    fmt::println("8. Documentation: Benchmark");
    fmt::println("9. Exit");
    if (auto result = scn::prompt< int >("Enter choice: ", "{}")) {
      const auto choice = result.value().value();

      switch (choice) {
      case 1:
        readFromFile();
        fmt::println("");
        break;
      case 2:
        generateData();
        fmt::println("");
        break;
      case 3:
        showData();
        fmt::println("");
        break;
      case 4:
        quickSort();
        fmt::println("");
        break;
      case 5:
        heapSort();
        fmt::println("");
        break;
      case 6:
        classicInsertionSort();
        fmt::println("");
        break;
      case 7:
        binaryInsertionSort();
        fmt::println("");
        break;
      case 8:
        benchmark();
        fmt::println("");
        break;
      case 9:
        fmt::println("Exiting...");
        std::exit(0);
      default:
        fmt::println("[!] Invalid choice. Please try again.\n");
      }
    } else {
      fmt::println("[!] Invalid input. Please enter a number.\n");
    }

    showMainMenu();
  }

private:
  ds::DynamicArray< int >   dataInt;
  ds::DynamicArray< float > dataFloat;
  DataType                  dataType{ DataType::NONE };

  void readFromFile() {
    fmt::println("> Read from file");
    fmt::println("1. Integer");
    fmt::println("2. Float");
    if (auto result = scn::prompt< int >("Enter choice: ", "{}")) {
      const auto choice = result.value().value();

      switch (choice) {
      case 1:
        if (auto result2 =
              scn::prompt< std::string >("Enter file path: (<path> %)", "{} %")) {
          const auto filePath = result2.value().value();
          fmt::println("Reading <INT> from file: {}", filePath);

          std::ifstream            file{ filePath };
          tool::ArrayReader< int > reader{ file };
          dataInt  = reader.read().first;
          dataType = DataType::INT;
        } else {
          fmt::println("[!] Invalid input.");
        }
        break;
      case 2:
        if (auto result2 =
              scn::prompt< std::string >("Enter file path: (<path> %)", "{} %")) {
          const auto filePath = result2.value().value();
          fmt::println("Reading <FLOAT> from file: {}", filePath);

          std::ifstream              file{ filePath };
          tool::ArrayReader< float > reader{ file };
          dataFloat = reader.read().first;
          dataType  = DataType::FLOAT;
        } else {
          fmt::println("[!] Invalid input.");
        }
        break;
      default:
        fmt::println("[!] Invalid choice.");
      }
    } else {
      fmt::println("[!] Invalid input.");
    }
  }

  void generateData() {
    fmt::println("> Generate data");
    fmt::println("1. Integer");
    fmt::println("2. Float");
    if (auto result = scn::prompt< int >("Enter choice: ", "{}")) {
      const auto choice = result.value().value();

      switch (choice) {
      case 1:
        if (auto result2 = scn::prompt< std::size_t >("Enter size: ", "{}")) {
          const auto size = result2.value().value();
          fmt::println("Generating <INT> data with size: {}", size);

          dataInt =
            tool::ArrayGenerator< int >{ size }.generatePureRandom(0, 100);
          dataType = DataType::INT;
        } else {
          fmt::println("[!] Invalid input.");
        }
        break;
      case 2:
        if (auto result2 = scn::prompt< std::size_t >("Enter size: ", "{}")) {
          const auto size = result2.value().value();
          fmt::println("Generating <FLOAT> data with size: {}", size);

          dataFloat = tool::ArrayGenerator< float >{ size }.generatePureRandom(
            0.0F, 100.0F);
          dataType = DataType::FLOAT;
        } else {
          fmt::println("[!] Invalid input.");
        }
        break;
      default:
        fmt::println("[!] Invalid choice.");
      }
    } else {
      fmt::println("[!] Invalid input.");
    }
  }

  void showData() {
    fmt::println("> Show data");
    fmt::print("Data: ");
    if (dataType == DataType::INT) {
      for (const auto& element : dataInt) { fmt::print("{} ", element); }
      fmt::print("\n");
    } else if (dataType == DataType::FLOAT) {
      for (const auto& element : dataFloat) { fmt::print("{:.2f} ", element); }
      fmt::print("\n");
    } else {
      fmt::println("[!] No data to show.");
    }
  }

  void quickSort() {
    fmt::println("> Quick sort");
    fmt::println("1. Ascending");
    fmt::println("2. Descending");
    if (auto result = scn::prompt< int >("Enter choice: ", "{}")) {
      const auto choice = result.value().value();

      switch (choice) {
      case 1:
        if (dataType == DataType::INT) {
          fmt::println("Sorting ascending integer data with quick sort ...");
          sort::quick::classic(std::begin(dataInt), std::end(dataInt));
          fmt::println("Done.");
        } else if (dataType == DataType::FLOAT) {
          fmt::println("Sorting ascending float data with quick sort ...");
          sort::quick::classic(std::begin(dataFloat), std::end(dataFloat));
          fmt::println("Done.");
        } else {
          fmt::println("[!] No data to sort.");
        }
        break;
      case 2:
        if (dataType == DataType::INT) {
          fmt::println("Sorting descending integer data with quick sort ...");
          sort::quick::classic(
            std::begin(dataInt), std::end(dataInt), std::greater<>{});
          fmt::println("Done.");
        } else if (dataType == DataType::FLOAT) {
          fmt::println("Sorting descending float data with quick sort ...");
          sort::quick::classic(
            std::begin(dataFloat), std::end(dataFloat), std::greater<>{});
          fmt::println("Done.");
        } else {
          fmt::println("[!] No data to sort.");
        }
        break;
      default:
        fmt::println("[!] Invalid choice.");
      }
    } else {
      fmt::println("[!] Invalid input.");
    }
  }

  void heapSort() {
    fmt::println("> Heap sort");
    fmt::println("1. Ascending");
    fmt::println("2. Descending");
    if (auto result = scn::prompt< int >("Enter choice: ", "{}")) {
      const auto choice = result.value().value();

      switch (choice) {
      case 1:
        if (dataType == DataType::INT) {
          fmt::println("Sorting ascending integer data with heap sort ...");
          sort::heap::classic(std::begin(dataInt), std::end(dataInt));
          fmt::println("Done.");
        } else if (dataType == DataType::FLOAT) {
          fmt::println("Sorting ascending float data with heap sort ...");
          sort::heap::classic(std::begin(dataFloat), std::end(dataFloat));
          fmt::println("Done.");
        } else {
          fmt::println("[!] No data to sort.");
        }
        break;
      case 2:
        if (dataType == DataType::INT) {
          fmt::println("Sorting descending integer data with heap sort ...");
          sort::heap::classic(
            std::begin(dataInt), std::end(dataInt), std::greater<>{});
          fmt::println("Done.");
        } else if (dataType == DataType::FLOAT) {
          fmt::println("Sorting descending float data with heap sort ...");
          sort::heap::classic(
            std::begin(dataFloat), std::end(dataFloat), std::greater<>{});
          fmt::println("Done.");
        } else {
          fmt::println("[!] No data to sort.");
        }
        break;
      default:
        fmt::println("[!] Invalid choice.");
      }
    } else {
      fmt::println("[!] Invalid input.");
    }
  }

  void classicInsertionSort() {
    fmt::println("> Classic insertion sort");
    fmt::println("1. Ascending");
    fmt::println("2. Descending");
    if (auto result = scn::prompt< int >("Enter choice: ", "{}")) {
      const auto choice = result.value().value();

      switch (choice) {
      case 1:
        if (dataType == DataType::INT) {
          fmt::println(
            "Sorting ascending integer data with classic insertion sort ...");
          sort::insertion::classic(std::begin(dataInt), std::end(dataInt));
          fmt::println("Done.");
        } else if (dataType == DataType::FLOAT) {
          fmt::println(
            "Sorting ascending float data with classic insertion sort ...");
          sort::insertion::classic(std::begin(dataFloat), std::end(dataFloat));
          fmt::println("Done.");
        } else {
          fmt::println("[!] No data to sort.");
        }
        break;
      case 2:
        if (dataType == DataType::INT) {
          fmt::println(
            "Sorting descending integer data with classic insertion sort ...");
          sort::insertion::classic(
            std::begin(dataInt), std::end(dataInt), std::greater<>{});
          fmt::println("Done.");
        } else if (dataType == DataType::FLOAT) {
          fmt::println(
            "Sorting descending float data with classic insertion sort ...");
          sort::insertion::classic(
            std::begin(dataFloat), std::end(dataFloat), std::greater<>{});
          fmt::println("Done.");
        } else {
          fmt::println("[!] No data to sort.");
        }
        break;
      default:
        fmt::println("[!] Invalid choice.");
      }
    } else {
      fmt::println("[!] Invalid input.");
    }
  }

  void binaryInsertionSort() {
    fmt::println("> Binary insertion sort");
    fmt::println("1. Ascending");
    fmt::println("2. Descending");
    if (auto result = scn::prompt< int >("Enter choice: ", "{}")) {
      const auto choice = result.value().value();

      switch (choice) {
      case 1:
        if (dataType == DataType::INT) {
          fmt::println(
            "Sorting ascending integer data with binary insertion sort ...");
          sort::insertion::binary(std::begin(dataInt), std::end(dataInt));
          fmt::println("Done.");
        } else if (dataType == DataType::FLOAT) {
          fmt::println(
            "Sorting ascending float data with binary insertion sort ...");
          sort::insertion::binary(std::begin(dataFloat), std::end(dataFloat));
          fmt::println("Done.");
        } else {
          fmt::println("[!] No data to sort.");
        }
        break;
      case 2:
        if (dataType == DataType::INT) {
          fmt::println(
            "Sorting descending integer data with binary insertion sort ...");
          sort::insertion::binary(
            std::begin(dataInt), std::end(dataInt), std::greater<>{});
          fmt::println("Done.");
        } else if (dataType == DataType::FLOAT) {
          fmt::println(
            "Sorting descending float data with binary insertion sort ...");
          sort::insertion::binary(
            std::begin(dataFloat), std::end(dataFloat), std::greater<>{});
          fmt::println("Done.");
        } else {
          fmt::println("[!] No data to sort.");
        }
        break;
      default:
        fmt::println("[!] Invalid choice.");
      }
    } else {
      fmt::println("[!] Invalid input.");
    }
  }

  static void benchmark() {
    fmt::println("> Benchmark");
    fmt::println(
      "Are you sure? This takes a long time and WILL erase current data.");
    if (auto result = scn::prompt< char >("Proceed? (y/n): ", "{}")) {
      const auto choice = result.value().value();

      if (choice == 'y') {
        fmt::println("Benchmarking ...");
        measure::allToFiles();
        fmt::println("Done.");
      } else {
        fmt::println("Aborted.");
      }
    } else {
      fmt::println("[!] Invalid input.");
    }
  }
};

} // namespace aizo

#endif // UNI_AIZO_P_AIZO_MENU_HPP
