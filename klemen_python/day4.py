import time
text_file = open("inputs/input_d4.txt", "r")
lines = text_file.readlines()
text_file.close()

print("Read {} passport lines.".format(len(lines)))

t0 = time.time()
blob = ""
blobs = 0
correct = 0
if not len(lines[len(lines)-1]) == 1:  # assure last line is always blank - ugly fix that'll do for now
    lines.append("\n")

for i in range(len(lines)-1):
    blob = blob+lines[i]

    if len(lines[i+1]) == 1:
        blobs += 1
        print(blob)
        if \
            'byr:' in blob and \
            'iyr:' in blob and \
            'eyr:' in blob and \
            'hgt:' in blob and \
            'hcl:' in blob and \
            'ecl:' in blob and \
            'pid:' in blob:

            correct += 1
            blob = ""
        else:
            blob = ""

    else:
        pass


print("found {} correct passports out of {} entries".format(correct, blobs))

t1 = time.time()

totalTime = t1-t0
print("elapsed: {} seconds for part 1.".format(round(totalTime, 4)))
