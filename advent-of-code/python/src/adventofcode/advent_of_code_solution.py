from .utils import readInput, log

class AdventOfCodeSolution:
    def __init__(self):
        pass

    def part1(self, data):
        return None

    def part2(self, data):
        return None

    def solve(self, day, expected_part1_test, expected_part2_test):
        advent_of_code_puzzle = AdventOfCodePuzzle(day)
        log(f"Day {day}")

        log("Part 1")
        self.check_part(advent_of_code_puzzle.part1_test_file, self.part1, expected_part1_test)
        input = readInput(advent_of_code_puzzle.input_file())
        log(f"result: {self.part1(input)}")

        if expected_part2_test is not None:
            log()
            log("Part 2")
            self.check_part(advent_of_code_puzzle.part2_test_file, self.part2, expected_part2_test)
            log(f"result: {self.part2(input)}")

    def check_part(self, puzzle_input, puzzle_part, expected_test):
        input = readInput(puzzle_input())
        part = puzzle_part(input)
        log(f"test: {part}")
        self.check(part == expected_test, f"solution was {part}, expected {expected_test}")

    def check(self, test, message):
        if not test:
            log(message)
            raise ValueError(message)


class AdventOfCodePuzzle:
    def __init__(self, day):
        self.__day = day
        self.__input_file = f"Day{day:02}"

    def input_file(self):
        return self.__input_file

    def part1_test_file(self):
        return f"{self.input_file()}_test"

    def part2_test_file(self):
        return self.part1_test_file()
