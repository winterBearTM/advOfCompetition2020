package utility

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
    }
}