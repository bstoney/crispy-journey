#include "advent_of_code_solution.hpp"

#include <format>

#include "utils.hpp"

template <typename TPart1, typename TPart2>
void AdventOfCodeSolution<TPart1, TPart2>::solve(int day, TPart1 expectedPart1Test, TPart2 expectedPart2Test) {
    std::string dayName = std::format("Day0{}", day);
    std::vector<std::string> data = utils::readInput(dayName);
    this->log("Part 1: ", this->part1(data));
    this->log("Part 2: ", this->part2(data));
}

template class AdventOfCodeSolution<int, int>;