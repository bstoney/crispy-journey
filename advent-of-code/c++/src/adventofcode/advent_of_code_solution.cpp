#include "advent_of_code_solution.hpp"
#include "advent_of_code_puzzle.hpp"

#include <format>

template <typename TPart1, typename TPart2>
void AdventOfCodeSolution<TPart1, TPart2>::solve(int day, TPart1 expectedPart1Test, TPart2 expectedPart2Test) {
    this->log(std::format("Day {}", day));
    AdventOfCodePuzzle* adventOfCodePuzzle = new AdventOfCodePuzzle(day);

    this->log("Part 1");
//    this->checkPart([adventOfCodePuzzle] () {
//            return adventOfCodePuzzle->part1TestFile();
//        },
//        [this] (std::vector<std::string> data) {
//            return this->part1(data);
//        }, expectedPart1Test);

    std::vector<std::string>testInput = utils::readInput(adventOfCodePuzzle->part1TestFile());
    auto testPart = this->part1(testInput);
    this->log(std::format("test: {}", testPart));
    this->check(testPart == expectedPart1Test, std::format("solution was {}, expected {}", testPart, expectedPart1Test));

    std::vector<std::string> input = utils::readInput(adventOfCodePuzzle->inputFile());
    this->log("result: ", this->part1(input));

    this->log("Part 2");
    std::vector<std::string>testInputPart2 = utils::readInput(adventOfCodePuzzle->part2TestFile());
    auto testPart2 = this->part2(testInputPart2);
    this->log(std::format("test: {}", testPart2));
    this->check(testPart2 == expectedPart2Test, std::format("solution was {}, expected {}", testPart2, expectedPart2Test));

    this->log("result: ", this->part2(input));
}

template <typename TPart1, typename TPart2>
void AdventOfCodeSolution<TPart1, TPart2>::checkPart(std::function<std::string()> puzzleInput,
                                                     std::function<auto(std::vector<std::string> data)> puzzlePart,
                                                     auto expectedTest) {
    std::string input = utils::readInput(puzzleInput());
    auto part = puzzlePart(input);
    this->log("test: {}", part);
    this->check(part == expectedTest, std::format("solution was {}, expected {}", part, expectedTest));
}

template <typename TPart1, typename TPart2>
void AdventOfCodeSolution<TPart1, TPart2>::check(bool test, std::string message) {
    if(!test) {
        throw std::runtime_error(message);
    }
}

template class AdventOfCodeSolution<int, int>;
template class AdventOfCodeSolution<long, long>;
