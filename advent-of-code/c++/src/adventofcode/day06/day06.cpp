#include "../advent_of_code_solution.hpp"

#include <string>
#include <vector>
#include <ranges>
#include <format>
#include <algorithm>

#include "../utils.hpp"

using namespace std;

struct Problem {
    char op;
    vector<string> args;
};

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

        this->debug("Problems: ", problemCount);
        this->debug("Arguments: ", argumentCount);

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

            this->log("- ", operators[i], " ", value);
            total += value;
        }

        return total;
    }

    long part2(vector<string> data) {
        vector<Problem*> problems;

        int operatorRow = data.size() - 1;

        int columns = 0;
        for (string input : data) {
            columns = max(columns, (int)input.size());
        }

        Problem* problem = new Problem();
        string currentNumber = "";
        for (int x = columns - 1; x >= 0; x--) {
            for (int y = 0; y < data.size(); y++) {
                char nextChar = data[y].size() <= x ? ' ' : data[y][x];
                if (y >= operatorRow) {
                    if (nextChar == '*' || nextChar == '+') {
                        problem->args.push_back(utils::trim(currentNumber));
                        problem->op = nextChar;
                        problems.push_back(problem);
                        problem = new Problem();
                        x--;
                    }
                    else {
                        problem->args.push_back(utils::trim(currentNumber));
                    }

                    currentNumber = "";
                }
                else {
                    currentNumber += nextChar;
                }
            }
        }

        this->debug("Problem count: ", problems.size());

        long total = 0;
        for (Problem* problem : problems) {
            long value = stol(problem->args[0]);
            for (int i = 1; i < problem->args.size(); i++) {
                if (problem->op == '*') {
                    value *= stol(problem->args[i]);
                }
                else if (problem->op == '+') {
                    value += stol(problem->args[i]);
                }
            }

            this->debug(utils::join(format(" {} ", problem->op), problem->args), " = ", value);
            total += value;
        }

        return total;
    }

    void solve() {
        super::solve(6, 4277556, 3263827);
    }

private:
};
