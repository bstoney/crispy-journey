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
    auto part = this->part1(testInput);
    this->log(std::format("test: {}", part));
    this->check(part == expectedPart1Test, std::format("solution was {}, expected {}", part, expectedPart1Test));

    std::vector<std::string> input = utils::readInput(adventOfCodePuzzle->inputFile());
    this->log("result: {}", this->part1(input));
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
