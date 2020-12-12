import advents.Day1
import advents.Day2

fun main(args: Array<String>) {
    day2()
}

private fun day1() {
    println("Day1 result first part: ${Day1().calculate2020Part1()}")
    println("Day1 result second part: ${Day1().calculate2020Part2()}")
}

private fun day2() {
    println("Day2 result first part: ${Day2().calculateValidPasswords()}")
}