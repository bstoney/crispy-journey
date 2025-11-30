#ifndef AOC_UTILS_HPP
#define AOC_UTILS_HPP

#include <string>
#include <vector>
#include <iostream>

std::vector<std::string> readInput(std::string name);

void log();

template<typename T, typename... TArgs>
void log(T value, TArgs... args) {
    std::cout << value;
    log(args...);
}

#endif // AOC_UTILS_HPP