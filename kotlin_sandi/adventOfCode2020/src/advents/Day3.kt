package advents

import utility.FileUtility

class Day3() : AdventDay() {
    override fun part1(): Int {
        return tobogganFun(3, 1)
    }

    override fun part2(): Int {
        return -1
    }

    fun part2Long(): Long { //need to use long, answer too long
        val list = mutableListOf<Int>()

        list.add(tobogganFun(1,1))
        list.add(tobogganFun(3,1))
        list.add(tobogganFun(5,1))
        list.add(tobogganFun(7,1))
        list.add(tobogganFun(1,2))

        var sum: Long = 1

        list.forEach {
            sum *= it
        }

        return sum
    }

    private fun tobogganFun(stepI: Int, stepJ: Int): Int {
        val map = readMapFromFile()

        var i=0
        var j = 0
        var treeCounter = 0
        while (j < map.size -1) {
            i += stepI
            j += stepJ

            if (i >= map[0].size) {
                extendMap(map)
            }

            if (map[j][i] == '#') {
                treeCounter += 1
            }
        }

        return treeCounter
    }

    private fun extendMap(map: Array<Array<Char>>) {
        val originalMap = readMapFromFile()

        map.forEachIndexed { index, a ->
            map[index] = a.plus(originalMap[index])

        }
    }

    private fun readMapFromFile(): Array<Array<Char>> {
        return FileUtility.readFile2D("day3_input")
    }

    override fun calculateResults(day: String) {
        println("$day result first part: ${part1()}")
        println("$day result second part: ${part2Long()}")
    }
}