#include "../advent_of_code_solution.hpp"

#include <string>
#include <vector>
#include <functional>

#include "../utils.hpp"

/*
    LT CT RT
    LM XY RM
    LB CB RB
*/

#define LEFT -1
#define MIDDLE +0
#define RIGHT +1
#define TOP -1
#define CENTER +0
#define BOTTOM +1

class Day04 : public AdventOfCodeSolution<int, int> {
private:
    typedef AdventOfCodeSolution<int, int> super;
public:
    int part1(std::vector<std::string> data) {
        int movableRolls = 0;
        for (int y = 0; y < data.size(); y++) {
            for (int x = 0; x < data[y].size(); x++) {
                if(this->isRoll(x, y, data)) {
                    int rollCount = this->countRolls(x, y, data);
                    this->debug(x, ",", y, " -> ", rollCount);
                    if(rollCount < 4) {
                        movableRolls++;
                    }
                }
            }
        }

        return movableRolls;
    }

    int part2(std::vector<std::string> data) {
        return 0;
    }

    void solve() {
        super::solve(4, 13, 0);
    }

private:
    int countRolls(int x, int y, std::vector<std::string> data) {
        return (this->isRoll(x LEFT, y TOP, data) ? 1 : 0) +
                (this->isRoll(x CENTER, y TOP, data) ? 1 : 0) +
                (this->isRoll(x RIGHT, y TOP, data) ? 1 : 0) +
                (this->isRoll(x RIGHT, y MIDDLE, data) ? 1 : 0) +
                (this->isRoll(x RIGHT, y BOTTOM, data) ? 1 : 0) +
                (this->isRoll(x CENTER, y BOTTOM, data) ? 1 : 0) +
                (this->isRoll(x LEFT, y BOTTOM, data) ? 1 : 0) +
                (this->isRoll(x LEFT, y MIDDLE, data) ? 1 : 0);
    }

    bool isRoll(int x, int y, std::vector<std::string> data) {
        if ( x < 0 || y < 0 || y >= data.size() || x >= data[y].size()) {
            return false;
        }

        return data[y][x] == '@';
    }
};
