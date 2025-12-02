#include <string>
#include <vector>

#include "../advent_of_code_solution.hpp"

class Day02 : public AdventOfCodeSolution<int, int> {
private:
    typedef AdventOfCodeSolution<int, int> super;
public:
    int part1(std::vector<std::string> data) {
        
        return data.size();
    }

    int part2(std::vector<std::string> data) {
        return data.size();
    }

    void solve() {
        super::solve(2, 1227775554, 0);
    }
};
