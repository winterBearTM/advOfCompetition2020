package utility

import data.PasswordCracker
import java.io.File

class FileUtility {
    companion object {
        fun readFile(filePath: String): MutableList<Int> {
            val list = mutableListOf<Int>()

            File("src/input/$filePath").readLines().forEach {
                list.add(it.toInt())
            }

            return list
        }

        fun readFilePassword(filePath: String): MutableList<PasswordCracker> {
            val list = mutableListOf<PasswordCracker>()

            File("src/input/$filePath").readLines().forEach {
                list.add(PasswordCracker(it))
            }

            return list
        }

        fun readFile2D(filePath: String): Array<Array<Char>> {
            val map = mutableListOf<Array<Char>>()
            File("src/input/$filePath").readLines().forEach {
                map.add(it.toCharArray().toTypedArray())
            }

            return map.toTypedArray()
        }
    }
}