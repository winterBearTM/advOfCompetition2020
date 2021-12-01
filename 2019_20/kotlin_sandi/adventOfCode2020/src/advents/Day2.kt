package advents

import utility.FileUtility.Companion.readFilePassword

class Day2(): AdventDay() {
    override fun part1(): Int {
        return calculateValidPasswords(true)
    }

    override fun part2(): Int {
        return calculateValidPasswords(false)
    }

    private fun calculateValidPasswords(part1: Boolean): Int {
        val list = readFilePassword("day2_input")


        var correct = 0
        for (a in list) {
            if (part1) {
                correct += if (a.isValidPart1()) 1 else 0
            } else {
                correct += if (a.isValidPart2()) 1 else 0
            }
        }

        return correct
    }
}