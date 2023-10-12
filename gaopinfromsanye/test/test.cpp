#include <iostream>
#include <string>
#include <vector>

bool isFileTypeSupported(const std::string& filename) {
    std::vector<std::string> supported_extensions = {"doc", "docx", "ppt", "xls", "xlsx", "pdf"};

    std::size_t pos = filename.rfind('.'); // Find the position of the last '.' in the filename
    if(pos == std::string::npos) {
        // No '.' found, return false
        return false;
    }

    std::string extension = filename.substr(pos + 1); // Get the extension
    for(const auto& supported_extension : supported_extensions) {
        if(extension == supported_extension) {
            return true;
        }
    }

    return false;
}

int main() {
    std::string filename = "example.docx";
    if(isFileTypeSupported(filename)) {
        std::cout << "File type is supported.\n";
    } else {
        std::cout << "File type is not supported.\n";
    }

    return 0;
}
