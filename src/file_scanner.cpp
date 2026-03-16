#include "file_scanner.h"

#include <algorithm>
#include <system_error>

namespace {

bool is_source_file(const std::filesystem::path& path) {
    const auto extension = path.extension().string();
    return extension == ".cpp" || extension == ".cc" || extension == ".h" ||
           extension == ".hpp";
}

}  // namespace

std::vector<std::filesystem::path> scan_directory(
    const std::filesystem::path& directory) {
    std::vector<std::filesystem::path> files;
    std::error_code error_code;

    if (!std::filesystem::exists(directory, error_code) ||
        !std::filesystem::is_directory(directory, error_code)) {
        return files;
    }

    const auto options =
        std::filesystem::directory_options::skip_permission_denied;

    for (std::filesystem::recursive_directory_iterator it(directory, options,
                                                          error_code),
         end;
         it != end; it.increment(error_code)) {
        if (error_code) {
            error_code.clear();
            continue;
        }

        if (!it->is_regular_file(error_code)) {
            error_code.clear();
            continue;
        }

        const auto& path = it->path();
        if (is_source_file(path)) {
            files.push_back(path);
        }
    }

    std::sort(files.begin(), files.end());
    return files;
}
