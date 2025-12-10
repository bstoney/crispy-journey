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
                            split_locations.add(self.key_of(x + 1, y))
                            output_row[x] = "|"
                        elif x > 0 and row[x - 1] == "^" and output_data[y - 1][x - 1] == "|":
                            split_locations.add(self.key_of(x - 1, y))
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
                debug(f"{y:03d}", "".join([str(x).center(3) for x in range(0, len(row))]))

            debug(f"{y:03d}", "".join([x.center(3) for x in row]))

        debug(sorted(split_locations))

        return len(split_locations)

    def part2(self, data):
        cache = {}

        y = 0
        x = data[y].index("S")
        paths = self.count_paths(data, x, y + 1, cache)

        return paths

    def count_paths(self, data, x, y, cache: dict[str, int]):
        key = self.key_of(x, y)
        if key in cache:
            return cache[key]

        if y <= 0:
            paths = self.count_paths(data, x, y + 1, cache)
            cache[key] = paths
            return paths
        elif y >= len(data):
            return 1
        else:
            cell = data[y][x]
            if cell == ".":
                paths = self.count_paths(data, x, y + 1, cache)
                cache[key] = paths
                return paths
            elif cell == "^":
                paths_1 = self.count_paths(data, x - 1, y + 1, cache)
                paths_2 = self.count_paths(data, x + 1, y + 1, cache)
                cache[key] = paths_1 + paths_2
                return paths_1 + paths_2
            else:
                return 0

    def key_of(self, x, y):
        return f"{y:03d},{x:03d}"

    def solve(self, *args):
        return super().solve(7, 21, 40)
