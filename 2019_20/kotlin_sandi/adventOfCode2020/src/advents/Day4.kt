package advents

import utility.FileUtility

class Day4(): AdventDay()  {
    override fun part1(): Int {
        return validatePassports(true)
    }

    override fun part2(): Int {
        return validatePassports(false)
    }

    private fun validatePassports(part1: Boolean): Int {
        val passports = FileUtility.readFilePassport("day4_input")

        var counter = 0
        for (a in passports) {
            if (part1) {
                counter += if (a.isValidPart1()) 1 else 0
            } else {
                counter += if (a.isValidPart2()) 1 else 0
            }
        }

        return counter
    }
}