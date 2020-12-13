import time
t0 = time.time()

text_file = open("inputs/input_d1.txt", "r")
lines = text_file.readlines()
text_file.close()
numbers = [int(line) for line in lines]
print("Read {} numbers:".format(len(numbers)))
print(numbers)

for i in range(len(numbers)):
    for j in range(len(numbers)):
        if numbers[i]+numbers[j]==2020:
            print(numbers[i])
            print(numbers[j])
            print(numbers[i]*numbers[j])
            break
    else:continue
    break
t1 = time.time()

totalTime = t1-t0
print("elapsed: {} seconds for part 1.".format(round(totalTime, 4)))


t0 = time.time()
for i in range(len(numbers)):
    for j in range(len(numbers)):
        for k in range(len(numbers)):
            if numbers[i] + numbers[j] + numbers[k] == 2020:
                print(numbers[i])
                print(numbers[j])
                print(numbers[k])
                print(numbers[i] * numbers[j] * numbers[k])
                break
        else:
            continue
        break
    else:
        continue
    break
t1 = time.time()
totalTime = t1-t0
print("elapsed: {} seconds for part 2.".format(round(totalTime, 4)))