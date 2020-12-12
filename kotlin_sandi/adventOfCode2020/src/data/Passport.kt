package data

class Passport {
    var byr: Int = -1 //(Birth Year)
    var iyr: Int = -1 //(Issue Year)
    var eyr: Int = -1 //(Expiration Year)
    var hgt = "" //(Height)
    var hcl = "" //(Hair Color)
    var ecl = "" //(Eye Color)
    var pid = "" //(Passport ID)
    var cid = "" //(Country ID)

    fun parse(inputStream: String) {
        val splitInputStream = inputStream.split(" ")
        for (a in splitInputStream) {
            val splitData = a.split(":")
            when (splitData[0]) {
                "byr" -> {
                    byr = splitData[1].toInt()
                }
                "iyr" -> {
                    iyr = splitData[1].toInt()
                }
                "eyr" -> {
                    eyr = splitData[1].toInt()
                }
                "hgt" -> {
                    hgt = splitData[1]
                }
                "hcl" -> {
                    hcl = splitData[1]
                }
                "ecl" -> {
                    ecl = splitData[1]
                }
                "pid" -> {
                    pid = splitData[1]
                }
                "cid" -> {
                    cid = splitData[1]
                }
            }
        }
    }

    fun isValidPart1(): Boolean {
        return byr != -1 && iyr != -1 && eyr != -1 && !hgt.isEmpty() && !hcl.isEmpty() &&
                !ecl.isEmpty() && !pid.isEmpty()
    }

    fun isValidPart2(): Boolean {
        return validateByr() && validateIyr() && validateEyr() && validateHgt() && validateHcl() &&
                validateEcl() && validatePid()
    }

    private fun validatePid(): Boolean {
        if (pid.length != 9) {
            return false
        }
        for (a in pid) {
            if (a.isDigit()) {
                continue
            }
            return false
        }

        return true
    }

    private fun validateEcl(): Boolean {
        when(ecl) {
            "amb", "blu", "brn", "gry", "grn", "hzl", "oth" -> {
                return true
            }
            else -> {
                return false
            }
        }
    }

    private fun validateHcl(): Boolean {
        return hcl.length == 7 && hcl[0] == '#' //todo add checks for 0-9 and af if necessary
    }

    private fun validateHgt(): Boolean {
        if (hgt.endsWith("cm")) {
            val parseNumber = hgt.substringBefore("cm").toInt()
            if (parseNumber in 150..193) {
                return true
            }
        } else if (hgt.endsWith("in")) {
            val parseNumber = hgt.substringBefore("in").toInt()
            if (parseNumber in 59..76) {
                return true
            }
        }

        return false
    }

    private fun validateEyr(): Boolean {
        return eyr in 2020..2030
    }

    private fun validateIyr(): Boolean {
        return iyr in 2010..2020
    }

    private fun validateByr(): Boolean {
        return byr in 1920..2002
    }

    override fun toString(): String {
        return "Passport(byr='$byr', iyr='$iyr', eyr='$eyr', hgt='$hgt', hcl='$hcl', ecl='$ecl', pid='$pid', cid='$cid')"
    }
}