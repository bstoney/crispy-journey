#include "../advent_of_code_solution.hpp"

#include <string>
#include <vector>
#include <functional>
#include <utility>
#include <algorithm>

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

using namespace std;

class Day04 : public AdventOfCodeSolution<int, int> {
private:
    typedef AdventOfCodeSolution<int, int> super;
public:
    int part1(vector<string> data) {
        auto movableRolls = this->getMoveableRolls(data);

        return movableRolls.size();
    }

    int part2(vector<string> data) {
        int totalRollsMoved = 0;
        int iterations = 0;
        vector<pair<int,int>> movableRolls = {};
        do {
            iterations++;
            if(iterations % 10 == 0) {
                this->debug("Iteration: ", iterations);
            }

            // Move
            for (auto [x,y] : movableRolls) {
                data[y][x] = '.';
            }
            totalRollsMoved += movableRolls.size();

            movableRolls = this->getMoveableRolls(data);
        } while(movableRolls.size() > 0);

        return totalRollsMoved;
    }

    void solve() {
        super::solve(4, 13, 43);
    }

private:
    vector<pair<int,int>> getMoveableRolls(vector<string> data) {
        vector<pair<int,int>> movableRolls = {};
        for (int y = 0; y < data.size(); y++) {
            for (int x = 0; x < data[y].size(); x++) {
                if(this->isRoll(x, y, data)) {
                    int rollCount = this->countRolls(x, y, data);
                    // this->debug(x, ",", y, " -> ", rollCount);
                    if(rollCount < 4) {
                        movableRolls.push_back({x, y});
                    }
                }
            }
        }

        return movableRolls;
    }
    int countRolls(int x, int y, vector<string> data) {
        auto adjacent = {
            this->isRoll(x LEFT, y TOP, data),
            this->isRoll(x CENTER, y TOP, data),
            this->isRoll(x RIGHT, y TOP, data),
            this->isRoll(x RIGHT, y MIDDLE, data),
            this->isRoll(x RIGHT, y BOTTOM, data),
            this->isRoll(x CENTER, y BOTTOM, data),
            this->isRoll(x LEFT, y BOTTOM, data),
            this->isRoll(x LEFT, y MIDDLE, data),
        };

        return count(adjacent.begin(), adjacent.end(), true);
    }

    bool isRoll(int x, int y, vector<string> data) {
        if ( x < 0 || y < 0 || y >= data.size() || x >= data[y].size()) {
            return false;
        }

        return data[y][x] == '@';
    }
};
