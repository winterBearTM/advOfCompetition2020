package data

import java.lang.Exception

data class PasswordCracker(val inputStream: String) {
    var minimum = -1
    var maximum = -1
    var character: Char = '-'
    var password = ""

    init {
        // format min-max char: input
        val split = inputStream.split(" ")
        val splitMinMax = split[0].split("-")
        minimum = splitMinMax[0].toInt()
        maximum = splitMinMax[1].toInt()

        character = split[1][0]

        password = split[2]
    }

    fun isValidPart1(): Boolean {
        val occurrences = password.count { it == character }

        return occurrences in minimum..maximum
    }

    fun isValidPart2(): Boolean {
        var part1 = false
        var part2 = false

        if (password[minimum - 1] == character) {
            part1 = true
        }

        if (maximum <= password.length) { // 01234 5 12 < 5
            if (password[maximum - 1] == character) {
                part2 = true
            }
        }

        return (part1 && !part2) || (!part1 && part2)
    }
}