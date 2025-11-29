package adventofcode.day01

import org.assertj.core.api.Assertions.assertThatCode
import org.junit.jupiter.api.Test

class Day01Test {
    @Test
    fun solve() {
        assertThatCode { Day01.solve() }.doesNotThrowAnyException()
    }
}