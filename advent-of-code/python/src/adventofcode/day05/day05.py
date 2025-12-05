from enum import Enum

from src.adventofcode.advent_of_code_solution import AdventOfCodeSolution
from src.adventofcode.utils import debug


class ReadMode(Enum):
    FRESH_INGREDIENTS = 1
    INGREDIENT_IDS = 2


class Day05(AdventOfCodeSolution):
    def __init__(self):
        super().__init__()

    def part1(self, data):
        fresh_ingredient_id_ranges, ingredient_ids = self.parse_inputs(data)

        fresh_ingredient_ids = set()
        for ingredient_id in ingredient_ids:
            for (range_start, range_end) in fresh_ingredient_id_ranges:
                if range_start <= ingredient_id <= range_end:
                    fresh_ingredient_ids.add(ingredient_id)

        return len(fresh_ingredient_ids)

    def part2(self, data):
        fresh_ingredient_id_ranges, ingredient_ids = self.parse_inputs(data)

        fresh_ingredient_ids = 0
        for (range_start, range_end) in fresh_ingredient_id_ranges:
            debug(
                f"{range_start} - {range_end} -> {range_end - range_start + 1} {[*range(range_start, min(range_end + 1, range_start + 20))]}")
            fresh_ingredient_ids += range_end - range_start + 1

        return fresh_ingredient_ids

    def parse_inputs(self, data) -> tuple[list[tuple[int, int]], set[int]]:
        fresh_ingredient_id_ranges = []
        ingredient_ids = set()

        read_mode = ReadMode.FRESH_INGREDIENTS
        for input in data:
            if input == "":
                read_mode = ReadMode.INGREDIENT_IDS
                continue
            if read_mode == ReadMode.FRESH_INGREDIENTS:
                range_start, range_end = input.split("-")
                fresh_ingredient_id_ranges = self.add_range(fresh_ingredient_id_ranges, int(range_start),
                                                            int(range_end))
            elif read_mode == ReadMode.INGREDIENT_IDS:
                ingredient_ids.add(int(input))

        debug("Fresh id ranges: ", len(fresh_ingredient_id_ranges))
        debug("Ingredients ids: ", len(ingredient_ids))

        return fresh_ingredient_id_ranges, ingredient_ids

    def solve(self, *args):
        return super().solve(5, 3, 14)

    def add_range(self, id_ranges, new_range_start, new_range_end):
        """Adds or updated the ranges to produce an order list of discrete ranges"""

        # Noop on invalid range
        if new_range_start > new_range_end:
            debug(f"Skipping invalid range: {new_range_start}:{new_range_end}")
            return id_ranges

        new_range_index = None
        for index, id_range in enumerate(id_ranges):
            id_range_start, id_range_end = id_range
            if new_range_end < id_range_start:
                # New range completely before id range
                new_range_index = index - 1
                break
            elif id_range_end < new_range_start:
                # New range completely after id range
                continue
            else:
                # New range has some overlap
                new_range_index = index
                break

        if new_range_index is None:
            debug(f"New range is after last id range: {new_range_start}:{new_range_end}")
            id_ranges.append([new_range_start, new_range_end])
        elif new_range_index < 0:
            debug(f"New range is before first id range: {new_range_start}:{new_range_end}")
            id_ranges.insert(-1, [new_range_start, new_range_end])
        else:
            id_range_start, id_range_end = id_ranges[new_range_index]
            if id_range_start <= new_range_start and new_range_end <= id_range_end:
                debug(f"No change to {new_range_index} [{id_range_start}<{new_range_start}:{new_range_end}>{id_range_end}]")
            else:
                debug(
                    f"New range overlaps with existing id range: {new_range_start}:{new_range_end} -> {id_ranges[new_range_index]}")
                updated_range_start = min(id_range_start, new_range_start)
                updated_range_end = max(id_range_end, new_range_end)

                # Compact if overlapping
                if new_range_index + 1 < len(id_ranges):
                    next_range_start, next_range_end = id_ranges[new_range_index + 1]
                    if updated_range_end >= next_range_start:
                        debug(f"    Compacting new range overlaps with new range: {updated_range_end} -> {id_ranges[new_range_index + 1]}")
                        del id_ranges[new_range_index + 1]
                        updated_range_end = max(updated_range_end, next_range_end)

                debug(f"    Updating range: {new_range_index} -> {[updated_range_start, updated_range_end]}")

                id_ranges[new_range_index] = [updated_range_start, updated_range_end]

        return id_ranges
