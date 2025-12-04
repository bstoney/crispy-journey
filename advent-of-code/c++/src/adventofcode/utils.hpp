#ifndef AOC_UTILS_HPP
#define AOC_UTILS_HPP

#include "app.hpp"

#include <string>
#include <vector>
#include <iostream>

namespace utils {
    std::vector<std::string> readInput(std::string name);

    void log();

    template<typename T, typename... TArgs>
    void log(T value, TArgs... args) {
        std::cout << value;
        log(args...);
    }

    template<typename... TArgs>
    void debug(TArgs... args) {
        #ifdef AOC_DEBUG
        log(args...);
        #endif
    }

    std::string trim(const std::string& str);

    std::string join(std::string seperator, std::vector<std::string> strings);

    std::string join(std::vector<std::string> strings);

    std::vector<std::string> split(std::string seperator, std::string value);
}

#endif // AOC_UTILS_HPP