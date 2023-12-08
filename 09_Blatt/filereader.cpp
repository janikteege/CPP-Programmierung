#include <fstream>
#include <filesystem>
#include <string>
#include <iostream>

namespace fs = std::filesystem;

int main()
{   
    std::string path = "./";
    std::cout << "Current path is " << fs::current_path() << '\n';
    std::cout << "Files are: \n";
    for (const auto & entry : fs::directory_iterator(path)) {
        std::cout << entry.path() << std::endl;
        if (entry.is_regular_file() &&
        (strcmp(entry.path().extension().c_str(),".hh") == 0 || strcmp(entry.path().extension().c_str(), ".cc") == 0)) {
            std::ifstream testFile {entry.path().c_str()};
            // Check if the file is open
            if (!testFile.is_open()) {
                std::cerr << "Error opening the file." << std::endl;
                return 1; // Return an error code
            }
            // Read and print the contents of the file
            std::string line;
            while (std::getline(testFile, line)) {
                std::cout << line << std::endl;
            }
            // Close the file
            testFile.close();
        }
    }
}