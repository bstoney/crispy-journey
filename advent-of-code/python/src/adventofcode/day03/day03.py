from src.adventofcode.advent_of_code_solution import AdventOfCodeSolution
from src.adventofcode.utils import debug

class Day03(AdventOfCodeSolution):
    def __init__(self):
        super().__init__()

    def part1(self, data):
        voltage = 0
        for bank_voltage in self.bank_voltages(data, 2):
            voltage += bank_voltage

        return voltage

    def part2(self, data):
        voltage = 0
        for bank_voltage in self.bank_voltages(data, 12):
            voltage += bank_voltage

        return voltage

    def bank_voltages(self, data, battery_count):
        for bank in data:
            batteries = self.get_batteries(bank, battery_count)
            yield int("".join(batteries))

    def get_batteries(self, bank, battery_count):
        debug(bank, " get ", battery_count)

        if len(bank) <= battery_count:
            return bank
        elif battery_count == 1:
            return max(*bank)

        max_battery = max(*bank[0:1 - battery_count])
        max_battery_index = bank.find(max_battery)
        debug("found ", max_battery, " at ", max_battery_index)
        batteries = [max_battery, *self.get_batteries(bank[max_battery_index + 1:], battery_count - 1)]
        return batteries

    def solve(self, *args):
        return super().solve(3, 357, 3121910778619)
