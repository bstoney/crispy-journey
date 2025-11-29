package adventofcode

private const val ENABLE_DEBUG = false

abstract class AdventOfCodeSolution<TSolution>(debug: Boolean = ENABLE_DEBUG) :
    AdventOfCodeSolution2Part<TSolution, TSolution>(debug)

abstract class AdventOfCodeSolution2Part<TPart1, TPart2>(private val debug: Boolean = ENABLE_DEBUG) {
    open fun part1(input: List<String>): TPart1? {
        return null
    }

    open fun part2(input: List<String>): TPart2? {
        return null
    }

    abstract fun solve()

    fun solve(day: Int, expectedPart1Test: TPart1, expectedPart2Test: TPart2? = null) {
        try {
            val adventOfCodePuzzle = AdventOfCodePuzzle(day)
            log("Day $day")

            log("Part 1")
            checkPart(adventOfCodePuzzle::part1TestFile, this::part1, expectedPart1Test)
            val input = readInput(adventOfCodePuzzle.inputFile())
            log("result: ${part1(input)}")

            if (expectedPart2Test != null) {
                log()
                log("Part 2")
                checkPart(adventOfCodePuzzle::part2TestFile, this::part2, expectedPart2Test)
                log("result: ${part2(input)}")
            }
        } catch (e: Exception) {
            log("Error: ${e.message}")
            throw e
        }
    }

    fun log(message: Any = "") {
        println(message)
    }

    fun debug(message: Any) {
        if (debug) {
            println(message)
        }
    }

    private fun <TPart> checkPart(puzzleInput: PuzzleInput, puzzlePart: PuzzlePart<TPart>, expectedTest: TPart) {
        val input = readInput(puzzleInput())
        val part = puzzlePart(input)
        log("test: $part")
        check(part == expectedTest) { "solution was $part, expected $expectedTest" }
    }
}
