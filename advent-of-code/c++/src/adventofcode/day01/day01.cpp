#include <string>
#include <vector>

#include "../advent_of_code_solution.hpp"

class Day01 : public AdventOfCodeSolution<int, int> {
private:
    typedef AdventOfCodeSolution<int, int> super;
public:
    Day01() {
    }

    ~Day01() {
    }

    int part1(std::vector<std::string> data) {
        return data.size();
    }

    int part2(std::vector<std::string> data) {
        return data.size();
    }

    void solve() {
        super::solve(1, 1, 1);
    }
};

int main() {
    Day01 day;
    day.solve();
    return 0;
}