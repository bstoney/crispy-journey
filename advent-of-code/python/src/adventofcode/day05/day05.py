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
        fresh_ingredient_id_ranges = {}
        ingredient_ids = set()

        read_mode = ReadMode.FRESH_INGREDIENTS
        for input in data:
            if input == "":
                read_mode = ReadMode.INGREDIENT_IDS
                continue
            if read_mode == ReadMode.FRESH_INGREDIENTS:
                range_start, range_end = input.split("-")
                # Start and end may be the same
                fresh_ingredient_id_ranges[input] = [int(range_start), int(range_end) + 1]
            elif read_mode == ReadMode.INGREDIENT_IDS:
                ingredient_ids.add(int(input))

        debug("Fresh id ranges: ", len(fresh_ingredient_id_ranges))
        debug("Ingredients ids: ", len(ingredient_ids))

        fresh_ingredient_ids = set()
        for ingredient_id in ingredient_ids:
            for (range_start, range_end) in fresh_ingredient_id_ranges.values():
                if range_start <= ingredient_id <= range_end:
                    fresh_ingredient_ids.add(ingredient_id)

        return len(fresh_ingredient_ids)

    def part2(self, data):
        fresh_ingredients = 0

        return fresh_ingredients

    def solve(self, *args):
        return super().solve(5, 3, None)
