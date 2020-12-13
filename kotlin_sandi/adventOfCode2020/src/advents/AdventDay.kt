package advents

abstract class AdventDay {
    abstract fun part1(): Int
    abstract fun part2(): Int

    open fun calculateResults(day: String) {
        println("$day result first part: ${part1()}")
        println("$day result second part: ${part2()}")
    }
}