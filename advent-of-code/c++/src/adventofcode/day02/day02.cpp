#include "../advent_of_code_solution.hpp"

#include <string>
#include <vector>

#include "../utils.hpp"

class Day02 : public AdventOfCodeSolution<long, long> {
private:
    typedef AdventOfCodeSolution<long, long> super;
public:
    long part1(std::vector<std::string> data) {
        std::string input = utils::join(std::string(""), data);
        this->log(input);

        std::vector<std::string> items = utils::split(std::string(","), input);
        long sum = 0;
        for (std::string item : items) {
            this->debug("Checking range: ", item);
            std::vector idRange = utils::split(std::string("-"), item);
            long start = std::stol(idRange[0]);
            long end = std::stol(idRange[1]);
            for (long i = start; i <= end; i++) {
                std::string id = std::to_string(i);
                if (id.size() % 2 == 0) {
                    int halfSize = id.size() / 2;
                    if (id.compare(0, halfSize, id, halfSize, halfSize) == 0) {
                        this->debug("Found invalid id: ", id);
                        sum += i;
                    }
                }
            }
        }

        return sum;
    }

    long part2(std::vector<std::string> data) {
        return data.size();
    }

    void solve() {
        super::solve(2, 1227775554, 0);
    }

private:
};
