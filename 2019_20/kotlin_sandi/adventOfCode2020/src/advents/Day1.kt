package advents

import utility.FileUtility.Companion.readFile
class Day1: AdventDay() {
    override fun part1(): Int {
        val list = readFile("day1_input")

        list.forEach {
            val desiredValue = 2020 - it
            if (list.contains(desiredValue)) {
                return it * desiredValue
            }
        }

        /*for (a in list) {
            for (b in list) {
                if (a + b == 2020) {
                    return a * b //910539
                }
            }
        }*/

        return -1
    }

    override fun part2(): Int {
        val list = readFile("day1_input")

        list.forEach {
            val desiredSum = (2020 - it)
            for (a in list) {
                val desiredThirdValue = desiredSum - a
                if (list.contains(desiredThirdValue)) {
                    return it * a * (desiredThirdValue)
                }
            }
        }

        /*for (a in list) {
            for (b in list) {
                for (c in list) {
                    if ((a + b + c) == 2020) { //116724144
                        return a * b * c
                    }
                }
            }
        }*/

        return -1
    }
}