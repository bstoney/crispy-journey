package adventofcode

class AdventOfCodePuzzle(day: Int) {
    private val inputFile: String = "Day" + day.toString().padStart(2, '0')

    fun inputFile() = inputFile

    fun part1TestFile() = "${inputFile}_test"

    fun part2TestFile() = part1TestFile()
}
