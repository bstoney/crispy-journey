from src.adventofcode.advent_of_code_solution import AdventOfCodeSolution
from src.adventofcode.utils import debug


class Day07(AdventOfCodeSolution):
    def __init__(self):
        super().__init__()

    def part1(self, data):
        split_locations = set()
        output_data = []
        for y, row in enumerate(data):
            output_row = list(row)
            if y > 0:
                for x, cell in enumerate(row):
                    if cell == ".":
                        if x < len(row) - 1 and row[x + 1] == "^" and output_data[y - 1][x + 1] == "|":
                            split_locations.add(f"{y:02d},{x + 1:02d}")
                            output_row[x] = "|"
                        elif x > 0 and row[x - 1] == "^" and output_data[y - 1][x - 1] == "|":
                            split_locations.add(f"{y:02d},{x - 1:02d}")
                            output_row[x] = "|"
                        elif output_data[y - 1][x] == "S" or output_data[y - 1][x] == "|":
                            output_row[x] = "|"
                        else:
                            output_row[x] = "."

                    else:
                        output_row[x] = cell

            output_data.append(output_row)

        for y, row in enumerate(output_data):
            if y == 0:
                debug(f"{y:02d}", "".join([str(x).center(3) for x in range(0, len(row))]))

            debug(f"{y:02d}", "".join([x.center(3) for x in row]))

        debug(sorted(split_locations))

        return len(split_locations)

    def part2(self, data):
        return 0

    def solve(self, *args):
        return super().solve(7, 21, None)
