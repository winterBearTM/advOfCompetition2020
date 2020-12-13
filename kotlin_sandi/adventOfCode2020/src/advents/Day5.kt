package advents

import data.BoardingSeat
import utility.FileUtility

class Day5 {
    fun part1(): Int {
        val list = FileUtility.readFileBoardingSeats("day5_input")

        var maxId = -1

        for (a in list) {
            val newSeatID = a.getSeatID()
            if (newSeatID > maxId) {
                maxId = newSeatID
            }
        }

        return maxId
    }

    fun part2(): Int {
        val list = FileUtility.readFileBoardingSeats("day5_input")

        var listOfIds = mutableListOf<Int>()

        for (a in list) {
            listOfIds.add(a.getSeatID())
        }

        listOfIds.sort()

        var previous = listOfIds[0]
        var current = listOfIds[1]

        for (a in listOfIds.subList(1, listOfIds.size)) {
            current = a

            if ((previous + 1) != current) {
                return previous +1
            }

            previous = current
        }

        return -1
    }

}