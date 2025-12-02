from src.adventofcode.advent_of_code_solution import AdventOfCodeSolution
from src.adventofcode.utils import log, debug

class Day01(AdventOfCodeSolution):
    def __init__(self):
        super().__init__()

    def part1(self, data):
        count = 0
        current = 50
        for direction, distance, _ in self.instruction_vectors(data):
            current += direction * distance
            current = current % 100
            if current == 0:
                count += 1


        return count

    def part2(self, data):
        count = 0
        current = 50

        for direction, distance, instruction in self.instruction_vectors(data):
            newCurrent, rotations = self.step(current, direction, distance)

            count += rotations
            current = newCurrent
            if current == 0:
                debug(f"{instruction} -> {current} : {rotations}")
            elif rotations == 0:
                debug(f"{instruction} -> {current}")
            else:
                debug(f"{instruction} -> {current} : {rotations}")

        return count

    def step(self, current, direction, distance):
        rotations = 0
        for i in range(distance):
            current += direction
            current %= 100
            if current == 0:
                rotations += 1

        return current, rotations

    def instruction_vectors(self, data):
        for instruction in data:
            yield 1 if instruction[0:1] == "R" else -1, int(instruction[1:]), instruction

    def solve(self, *args):
        return super().solve(1, 3, 6)

if __name__ == "__main__":
    Day01().solve()
