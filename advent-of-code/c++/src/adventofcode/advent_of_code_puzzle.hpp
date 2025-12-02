#ifndef AOC_PUZZLE_HPP
#define AOC_PUZZLE_HPP

#include <string>
#include <format>

class AdventOfCodePuzzle {
public:
    AdventOfCodePuzzle(int day) {
        this->_day = day;
        this->_inputFile = std::format("Day{:02}", this->_day);
    }

    std::string inputFile() {
        return this->_inputFile;
    }

    std::string part1TestFile() {
        return std::format("{}_test", this->inputFile());
    }

    std::string part2TestFile() {
        return this->part1TestFile();
    }
private:
    int _day;
    std::string _inputFile;
};

#endif // AOC_PUZZLE_HPP