package adventofcode.day01

import adventofcode.AdventOfCodeSolution

fun main() {
    Day01.solve()
}

object Day01 : AdventOfCodeSolution<Int>() {
    override fun solve() {
        solve(1, 1, 1)
    }

    override fun part1(input: List<String>): Int {
        return input.size
    }

    override fun part2(input: List<String>): Int {
        return input.size
    }
}