from enum import Enum
from typing import Self, Any

from src.adventofcode.advent_of_code_solution import AdventOfCodeSolution
from src.adventofcode.utils import debug


class ReadMode(Enum):
    FRESH_INGREDIENTS = 1
    INGREDIENT_IDS = 2


class IdRange:
    def __init__(self, id_range: tuple[Any, Any] | str):
        if isinstance(id_range, str):
            range_start, range_end = id_range.split("-")
        else:
            range_start, range_end = id_range
        self.start = int(range_start)
        self.end = int(range_end)

    def id_count(self):
        return self.end - self.start + 1

    def joins_to_end(self, other: Self):
        """True if other can be joined to the start of this"""
        return self.start <= other.start and self.end >= other.start - 1

    def is_valid(self):
        return self.start <= self.end

    def extend_to(self, other: Self):
        """Extends the range to cover from the min start to max end without any verification of intersection"""
        self.start = min(self.start, other.start)
        self.end = max(self.end, other.end)

    def __str__(self):
        return f"r[{self.start:,}-{self.end:,}]"

    def details(self):
        return f"{self} -> {self.id_count():,} {[*range(self.start, min(self.end + 1, self.start + 20))]}"


class Day05(AdventOfCodeSolution):
    def __init__(self):
        super().__init__()

    def part1(self, data):
        fresh_ingredient_id_ranges, ingredient_ids = self.parse_inputs(data)

        fresh_ingredient_ids = set()
        for ingredient_id in ingredient_ids:
            for id_range in fresh_ingredient_id_ranges:
                if id_range.start <= ingredient_id <= id_range.end:
                    fresh_ingredient_ids.add(ingredient_id)

        return len(fresh_ingredient_ids)

    def part2(self, data):
        fresh_ingredient_id_ranges, ingredient_ids = self.parse_inputs(data)

        fresh_ingredient_ids = 0
        for id_range in fresh_ingredient_id_ranges:
            debug(id_range.details())
            fresh_ingredient_ids += id_range.id_count()

        return fresh_ingredient_ids

    def parse_inputs(self, data: list[str]) -> tuple[list[IdRange], set[int]]:
        fresh_ingredient_id_ranges = []
        ingredient_ids = set()

        read_mode = ReadMode.FRESH_INGREDIENTS
        for data_item in data:
            if data_item == "":
                read_mode = ReadMode.INGREDIENT_IDS
                continue
            if read_mode == ReadMode.FRESH_INGREDIENTS:
                id_range = IdRange(data_item)
                fresh_ingredient_id_ranges = Day05.add_range(fresh_ingredient_id_ranges, id_range)
            elif read_mode == ReadMode.INGREDIENT_IDS:
                ingredient_ids.add(int(data_item))

        debug("Fresh id ranges: ", len(fresh_ingredient_id_ranges))
        debug("Ingredients ids: ", len(ingredient_ids))

        compacted_fresh_ingredient_id_ranges = Day05.compact(fresh_ingredient_id_ranges)

        debug("Fresh id ranges: ", len(compacted_fresh_ingredient_id_ranges))

        return compacted_fresh_ingredient_id_ranges, ingredient_ids

    def solve(self, *args):
        return super().solve(5, 3, 14)

    @staticmethod
    def add_range(id_ranges: list[IdRange], new_range: IdRange) -> list[IdRange]:
        """Adds or updated the ranges to produce an order list of ranges"""

        if not new_range.is_valid():
            # Noop on invalid range
            debug(f"Skipping invalid range: {new_range}")
            return id_ranges

        for index, id_range in enumerate(id_ranges):
            if new_range.start > id_range.start:
                # Keep searching if new range is greater
                continue
            else:
                debug(f"New range {new_range} inserted at {index}")
                id_ranges.insert(index, new_range)
                return id_ranges

        debug(f"New range {new_range} appended at {len(id_ranges)}")
        id_ranges.append(new_range)
        return id_ranges

    @staticmethod
    def compact(id_ranges: list[IdRange]) -> list[IdRange]:
        """Compacts an order list of ranges so there is no overlap"""
        compacted_id_ranges = [id_ranges[0]]
        for index, id_range in enumerate(id_ranges[1:]):
            if compacted_id_ranges[-1].joins_to_end(id_range):
                compacted_id_ranges[-1].extend_to(id_range)
            else:
                compacted_id_ranges.append(id_range)

        return compacted_id_ranges
