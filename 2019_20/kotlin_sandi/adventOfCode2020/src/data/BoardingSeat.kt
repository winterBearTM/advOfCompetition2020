package data

data class BoardingSeat(val inputStream: String) {
    var row = -1
    var column = -1

    init {
        parseRow()
        parseColumn()
    }

    private fun parseRow() {
        row = decode(getRowInput(), 'F', 'B', 128)
    }

    private fun parseColumn() {
        column = decode(getColumnInput(), 'L', 'R', 8)
    }

    private fun getRowInput(): String {
        return inputStream.substring(0,7)
    }

    private fun getColumnInput(): String {
        return inputStream.substring(7,10)
    }

    private fun decode(input: String, lowerHalf: Char, upperHalf: Char, limit: Int): Int {
        var min = 0
        var max = limit
        var lastChar = '-'

        for (a in input) {
            val half = (max - min) / 2
            lastChar = a
            if (a == lowerHalf) {
                // min ostane isti
                // max je 1/2
                max = min + half
            } else {
                min = max - half
                // min je 1/2
                // max ostane isti
            }
        }

        return if (lastChar == lowerHalf) {
            min
        } else {
            max -1
        }

    }

    fun getSeatID(): Int {
        return (row * 8) + column
    }
}