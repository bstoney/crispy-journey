#include "../advent_of_code_solution.hpp"

#include <string>
#include <vector>
#include <functional>

#include "../utils.hpp"

class Day02 : public AdventOfCodeSolution<long, long> {
private:
    typedef AdventOfCodeSolution<long, long> super;
public:
    long part1(std::vector<std::string> data) {
        auto isInvalid = [](long id) {
            std::string idStr = std::to_string(id);
            if (idStr.size() % 2 == 0) {
                int halfSize = idStr.size() / 2;
                if (idStr.compare(0, halfSize, idStr, halfSize, halfSize) == 0) {
                    return true;
                }
            }

            return false;
        };

        return this->getSumOfInvalid(data, isInvalid);
    }

    long part2(std::vector<std::string> data) {
        auto isInvalid = [](long id) {
            std::string idStr = std::to_string(id);
            int halfSize = idStr.size() / 2;
            for (int chunkSize = 1; chunkSize <= halfSize; chunkSize++) {
                if (idStr.size() % chunkSize == 0) {
                    int chunkCount = idStr.size() / chunkSize;
                    bool allChunksMatch = true;
                    for (int i = 1; i < chunkCount; i++) {
                        if (idStr.compare(0, chunkSize, idStr, chunkSize * i, chunkSize) != 0) {
                            allChunksMatch = false;
                            break;
                        }
                    }

                    if (allChunksMatch) {
                        return true;
                    }
                }
            }

            return false;
        };

        return this->getSumOfInvalid(data, isInvalid);
    }

    void solve() {
        super::solve(2, 1227775554, 4174379265);
    }

private:
    long getSumOfInvalid(std::vector<std::string> data, std::function<bool(long)> isInvalid) {
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
                if(isInvalid(i)) {
                    this->debug("Found invalid id: ", i);
                    sum += i;
                }
            }
        }

        return sum;
    }
};
