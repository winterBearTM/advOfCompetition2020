package utility

import data.BoardingSeat
import data.Passport
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

        fun readFilePassport(filePath: String): MutableList<Passport> {
            val list = mutableListOf<Passport>()
            var passport = Passport()
            File("src/input/$filePath").readLines().forEach {
                passport.parse(it)
                if (it.isEmpty()) {
                    list.add(passport)
                    passport = Passport()
                }
            }

            list.add(passport)

            return list
        }

        fun readFileBoardingSeats(filePath: String): MutableList<BoardingSeat> {
            val list = mutableListOf<BoardingSeat>()
            File("src/input/$filePath").readLines().forEach {
                list.add(BoardingSeat(it))
            }

            return list
        }

        fun readFileGroupAnswers(filePath: String): MutableList<MutableList<String>> {
            val list = mutableListOf<MutableList<String>>()
            var innerList = mutableListOf<String>()
            File("src/input/$filePath").readLines().forEach {
                if (it.isNotEmpty()) {
                    innerList.add(it)
                } else {
                    list.add(innerList)
                    innerList = mutableListOf<String>()
                }

            }

            list.add(innerList)

            return list
        }
    }
}