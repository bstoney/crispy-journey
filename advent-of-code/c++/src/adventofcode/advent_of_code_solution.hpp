#ifndef AOC_SOLUTION_HPP
#define AOC_SOLUTION_HPP

#include <string>
#include <vector>

#include "utils.hpp"

template <typename TPart1, typename TPart2>
class AdventOfCodeSolution {
public:
    virtual TPart1 part1(std::vector<std::string> data) = 0;
    virtual TPart2 part2(std::vector<std::string> data) = 0;
    void solve(int day);
};

#endif // AOC_SOLUTION_HPP