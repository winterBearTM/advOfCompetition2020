package advents

import utility.FileUtility.Companion.readFilePassword

class Day2() {
    fun calculateValidPasswords(): Int {
        val list = readFilePassword("day2_input")


        var correct = 0
        for (a in list) {
            correct += if (a.isValidPart2()) 1 else 0
        }

        return correct
    }
}