#include "../advent_of_code_solution.hpp"

#include <string>
#include <vector>
#include <ranges>
#include <format>

#include "../utils.hpp"

using namespace std;

class Day06 : public AdventOfCodeSolution<long, long> {
private:
    typedef AdventOfCodeSolution<long, long> super;
public:
    long part1(vector<string> data) {
        vector<vector<string>> input;
        for (string item : data) {
            vector<string> args;
            for (string arg : utils::split(" ", item) | views::filter([](string a) { return !a.empty(); })) {
                args.push_back(arg);
            }

            input.push_back(args);
        }

        vector<string> operators = input.back();

        int problemCount = operators.size();
        int argumentCount = input.size() - 1;

        utils::debug("Problems: ", problemCount);
        utils::debug("Arguments: ", argumentCount);

        long total = 0;
        for (int i = 0; i < problemCount; i++) {
            string op = operators[i];
            long value = stol(input[0][i]);
            for (int j = 1; j < argumentCount; j++) {
                if (op == "*") {
                    value *= stol(input[j][i]);
                }
                else if (op == "+") {
                    value += stol(input[j][i]);
                }
            }

            utils::log("- ", operators[i], " ", value);
            total += value;
        }

        return total;
    }

    long part2(vector<string> data) {
        return 0;
    }

    void solve() {
        super::solve(6, 4277556, 3263827);
    }

private:
};
