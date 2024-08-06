#include <filesystem>
#include <iostream>
#include <string>

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {
  try {
    if (argc == 0 || argv[0] == nullptr) {
      std::cerr << "Error: Cannot determine the executable name." << std::endl;
      return 1;
    }

    fs::path current_path = fs::current_path();

    fs::path executable_name = fs::path(argv[0]).filename();

    for (const auto& entry : fs::recursive_directory_iterator(current_path)) {
      if (entry.is_regular_file() && entry.path().extension() == ".exe") {
        if (entry.path().filename() == executable_name) {
          std::cout << "Skipping: " << entry.path() << std::endl;
        } else {
          std::cout << "Deleting: " << entry.path() << std::endl;
          fs::remove(entry.path());
        }
      }
    }
  } catch (const fs::filesystem_error& e) {
    std::cerr << "Filesystem error: " << e.what() << std::endl;
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  return 0;
}
