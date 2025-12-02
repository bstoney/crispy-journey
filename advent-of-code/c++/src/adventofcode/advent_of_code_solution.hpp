#ifndef AOC_SOLUTION_HPP
#define AOC_SOLUTION_HPP

#include <string>
#include <vector>
#include <functional>

#include "utils.hpp"

template <typename TPart1, typename TPart2>
class AdventOfCodeSolution {
public:
    virtual TPart1 part1(std::vector<std::string> data) = 0;
    virtual TPart2 part2(std::vector<std::string> data) = 0;
    void solve(int day, TPart1 expectedPart1Test, TPart2 expectedPart2Test);

    template<typename... TArgs>
    void log(TArgs... args) {
        utils::log(args...);
    }
private:
    void checkPart(std::function<std::string()> puzzleInput,
                   std::function<auto(std::vector<std::string> data)> puzzlePart,
                   auto expectedTest);
    void check(bool test, std::string message);
};

#endif // AOC_SOLUTION_HPP