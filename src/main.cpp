#include "file_scanner.h"

#include <filesystem>
#include <iostream>

int main() {
    std::cout << "cpp_file_scanner started." << std::endl;

    const auto files = scan_directory(std::filesystem::current_path());
    for (const auto& file : files) {
        std::cout << file.string() << std::endl;
    }

    return 0;
}
