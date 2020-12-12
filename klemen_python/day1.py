import time
text_file = open("input.txt", "r")
lines = text_file.readlines()
text_file.close()
numbers = [int(line) for line in lines]
print("Read {} numbers:".format(len(lines)))
print(numbers)
t0 = time.time()

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
print("elapsed: {} milliseconds for part 1.".format(totalTime))


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
print("elapsed: {} milliseconds for part 2.".format(totalTime))