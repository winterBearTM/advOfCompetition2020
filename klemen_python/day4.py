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
        #print(blob)
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



print("found {} valid passports out of {} correct ones. ".format(correct, blobs))

t1 = time.time()

totalTime = t1-t0
print("elapsed: {} seconds for part 1.".format(round(totalTime, 4)))



t0 = time.time()
blob = ""
bad=0
blobs = 0
correct_blobs = []
correct = 0
if not len(lines[len(lines)-1]) == 1:  # assure last line is always blank - ugly fix that'll do for now
    lines.append("\n")

for i in range(len(lines)-1):
    blob = blob+lines[i]

    if len(lines[i+1]) == 1:
        blobs += 1
        #print(blob)
        if \
            'byr:' in blob and \
            'iyr:' in blob and \
            'eyr:' in blob and \
            'hgt:' in blob and \
            'hcl:' in blob and \
            'ecl:' in blob and \
            'pid:' in blob:

            correct += 1
            correct_blobs.append(blob)
            blob = ""
        else:
            blob = ""

    else:
        pass

for correctBlob in correct_blobs:
    currentblob = correctBlob.replace(' ','\n')
    splitblob = currentblob.split('\n')
    for line in splitblob:
        if 'byr' in line:
            if (1920 < int(line.split(':')[1]) < 2002):
                pass
            else:
                bad+1
                break 
        elif 'iyr' in line:
            if (2010 <= int(line.split(':')[1]) <= 2020):
                pass
            else:
                bad+1
                break 
        elif 'eyr' in line:
            if (2020 < int(line.split(':')[1]) < 2030):
                pass
            else:
                bad+1
                break 
        elif 'hgt' in line:
            val = str(line.split(':')[1])
            if 'in' in val and (150 < int(val.replace('in','')) < 193):
                pass
            elif 'cm' in val and (59 < int(val.replace('cm','')) < 76):
                pass
            else:
                bad+1
                break 
        elif 'hcl' in line:
            if line.split(':')[1]:
                pass
        elif 'ecl' in line:
            if line.split(':')[1]:
                pass
        elif 'pid' in line:
            if len(line.split(':')[1])==9:
                pass
            else:
                bad+1
                break            


print("found {} correct passports out of {} entries".format(bad, blobs))

t1 = time.time()

totalTime = t1-t0
print("elapsed: {} seconds for part 2.".format(round(totalTime, 4)))


