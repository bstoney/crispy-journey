#include "utils.hpp"
#include "app.hpp"

#include <fstream>

namespace utils {
    std::vector<std::string> readInput(std::string name) {
        std::string filename = "input/" + name + ".txt";
        debug("Reading file: ", filename);

        std::vector<std::string> lines;
        std::ifstream inputFile(filename);

        try {
            std::string line;
            while (std::getline(inputFile, line)) {
                lines.push_back(line);
            }
            inputFile.close();
        } catch (...) {
            inputFile.close();
            throw std::runtime_error("Failed to read file " + filename);
        }

        return lines;
    }

    void log() {
        std::cout << std::endl;
    }
}