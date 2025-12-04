from src.adventofcode.advent_of_code_solution import AdventOfCodeSolution
from src.adventofcode.utils import log, debug

class Day03(AdventOfCodeSolution):
    def __init__(self):
        super().__init__()

    def part1(self, data):
        voltage = 0
        for bank_voltage in self.bank_voltages(data):
            voltage += bank_voltage

        return voltage

    def part2(self, data):
        return 0

    def bank_voltages(self, data):
        for bank in data:
            max_battery = max(*bank[0:-1])
            max_battery_index = bank.find(max_battery)
            yield int(f"{max_battery}{max(*bank[max_battery_index+1:])}")

    def solve(self, *args):
        return super().solve(3, 357, None)

