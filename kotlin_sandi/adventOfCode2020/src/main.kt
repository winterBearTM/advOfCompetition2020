import advents.Day1
import advents.Day2
import advents.Day3

fun main(args: Array<String>) {
    day3()
}

private fun day1() {
    println("Day1 result first part: ${Day1().calculate2020Part1()}")
    println("Day1 result second part: ${Day1().calculate2020Part2()}")
}

private fun day2() {
    println("Day2 result second part: ${Day2().calculateValidPasswords()}")
}

private fun day3() {
    println("Day3 result first part: ${Day3().part1()}")
    println("Day3 result second part: ${Day3().part2()}")
}