package advents

import utility.FileUtility.Companion.readFileGroupAnswers
import java.util.*

class Day6: AdventDay() {
    override fun part1(): Int {

        val listOfLists = readFileGroupAnswers("day6_input")

        var sumOfAnsweredQuestions = 0

        for (innerList in listOfLists) {
            val resultGroup = mutableListOf<Char>()
            for (result in innerList) {
                for (question in result) {
                    resultGroup.add(question)
                }
            }

            sumOfAnsweredQuestions += resultGroup.distinct().size
        }

        return sumOfAnsweredQuestions
    }

    override fun part2(): Int {
        val listOfLists = readFileGroupAnswers("day6_input")

        var sumOfAnsweredQuestions = 0

        for (innerList in listOfLists) {
            val resultGroup = mutableListOf<Char>()
            for (result in innerList) {
                for (question in result) {
                    resultGroup.add(question)
                }
            }

            val counterForSuccess = innerList.size

            for (item in resultGroup.distinct()) {
                if (Collections.frequency(resultGroup, item) == counterForSuccess) {
                    sumOfAnsweredQuestions += 1
                }
            }
        }

        return sumOfAnsweredQuestions
    }

}