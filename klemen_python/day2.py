import time
text_file = open("inputs/input_d2.txt", "r")
lines = text_file.readlines()
text_file.close()

print("Read {} password lines.".format(len(lines)))

t0 = time.time()
correct = 0
for line in lines:
    occLimits = str(line.split(' ')[0]).split('-')[slice(0, 2)]
    keyAndPass = line.split(' ')[slice(1,3)]
    if int(occLimits[0]) <= keyAndPass[1].count(keyAndPass[0][0]) <= int(occLimits[1]):
        correct += 1

print(correct)
t1 = time.time()

totalTime = t1-t0
print("elapsed: {} seconds for part 1.".format(round(totalTime, 4)))


correct = 0
for line in lines:
    occLimits = str(line.split(' ')[0]).split('-')[slice(0, 2)]
    keyAndPass = line.split(' ')[slice(1, 3)]
    if (keyAndPass[1][int(occLimits[0])-1] == keyAndPass[0][0]) != (keyAndPass[1][int(occLimits[1])-1] == keyAndPass[0][0]):
        correct += 1

print(correct)
t1 = time.time()

totalTime = t1-t0
print("elapsed: {} seconds for part 2.".format(round(totalTime, 4)))

