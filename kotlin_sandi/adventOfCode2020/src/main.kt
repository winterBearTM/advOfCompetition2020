import advents.*

fun main(args: Array<String>) {
    var totalTime: Long = 0
    totalTime += day1()
    totalTime += day2()
    totalTime += day3()
    totalTime += day4()
    totalTime += day5()
    totalTime += day6()

    println("Total time: $totalTime ms")
}

private fun day1(): Long {
    return Day1().calculateResults("Day1")
}

private fun day2(): Long {
    return Day2().calculateResults("Day2")
}

private fun day3(): Long {
    return Day3().calculateResults("Day3")
}

private fun day4(): Long {
    return Day4().calculateResults("Day4")
}

private fun day5(): Long {
    return Day5().calculateResults("Day5")
}

private fun day6(): Long {
    return Day6().calculateResults("Day6")
}