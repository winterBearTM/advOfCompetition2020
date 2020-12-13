import time
text_file = open("inputs/input_d3.txt", "r")
lines = text_file.readlines()
text_file.close()
print("Read {} snowMap lines.".format(len(lines)))

t0 = time.time()
strafe = 3
trees = 0
for i in range(len(lines)):
    sidePos = (i*strafe) % 31
    if lines[i][sidePos] == '#':
        trees += 1

print("Encountered {} trees on 3 right, 1 down path.".format(trees))
t1 = time.time()

totalTime = t1-t0
print("elapsed: {} seconds for part 1.".format(round(totalTime, 7)))


t0 = time.time()
strafe = 3
trees = 0
treeproduct = 1
strafes = [1, 3, 5, 7]

for strafe in strafes:
    trees = 0
    for i in range(len(lines)):
        sidePos = (i*strafe) % 31
        if lines[i][sidePos] == '#':
            trees += 1
    treeproduct *= trees

trees = 0
strafe = 1
for i in range(len(lines)):
    sidePos = (i * strafe) % 31
    if i*2 >= len(lines):
        break
    if lines[i*2][sidePos] == '#':
        trees += 1

treeproduct *= trees

print("The product of all encountered trees is {}".format(treeproduct))
t1 = time.time()

totalTime = t1-t0
print("elapsed: {} seconds for part 2.".format(round(totalTime, 4)))


