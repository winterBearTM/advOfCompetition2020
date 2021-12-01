package advents

abstract class AdventDay {
    abstract fun part1(): Int
    abstract fun part2(): Int

    open fun calculateResults(day: String): Long {
        val part1TimerStart = System.currentTimeMillis()
        print("$day result first part: ${part1()}")
        val part1Timer = System.currentTimeMillis() - part1TimerStart
        println(", execution time = $part1Timer ms")
        val part2TimerStart = System.currentTimeMillis()
        print("$day result second part: ${part2()}")
        val part2Timer = System.currentTimeMillis() - part2TimerStart
        println(", execution time = $part2Timer ms")
        val totalTime = part1Timer + part2Timer
        println("$day total time: $totalTime ms")

        return totalTime
    }
}