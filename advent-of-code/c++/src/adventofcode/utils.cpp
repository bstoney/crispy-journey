#include "utils.hpp"
#include "app.hpp"

#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>

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

    std::string trim(const std::string& str) {
        size_t first = str.find_first_not_of(" \t\n\r");
        if (std::string::npos == first) {
            return str;
        }

        size_t last = str.find_last_not_of(" \t\n\r");
        return str.substr(first, (last - first + 1));
    }

    std::string join(std::string seperator, std::vector<std::string> strings) {
        std::string concatenated_string = std::accumulate(strings.begin(), strings.end(), std::string(""),
            [seperator](const std::string& acc, const std::string& current_str) {
                std::string trimmed_current = trim(current_str);
                if (acc.empty()) {
                    return trimmed_current;
                } else {
                    return acc + seperator + trimmed_current;
                }
            });

        return concatenated_string;
    }

    std::string join(std::vector<std::string> strings) {
        return join(std::string(" "), strings);
    }

    // Only using first char of separator
    std::vector<std::string> split(std::string seperator, std::string value) {
        std::vector<std::string> result;
        std::stringstream ss(value);
        std::string token;

        while (std::getline(ss, token, seperator[0])) {
            result.push_back(token);
        }

        return result;
    }
}