package advents.day1

import utility.FileUtility.Companion.readFile
class Day1 {
    fun calculate2020(): Int {
        val list = readFile("day1_input")

        for (a in list) {
            for (b in list) {
                if (a + b == 2020) {
                    return a * b
                }
            }
        }

        return -1
    }
}