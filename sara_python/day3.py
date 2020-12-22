#Part one
num_trees = 0
index = 0
for line in open('input3.txt', 'r'):
    line = line.strip()
    l = len(line)
    while index >= l:
        index -=l

    x = line[index]
    if x == '#':
        num_trees += 1

    index +=3

print(num_trees)

#part two
num_trees1 = num_trees2 = num_trees3 = num_trees4 = num_trees5 = 0
index1 = index2 = index3 = index4 = index5 = 0
for (i, line) in enumerate(open('input3.txt', 'r')):
    line = line.strip()
    l = len(line)
    while index1 >= l:
        index1 -=l
    while index2 >= l:
        index2 -=l
    while index3 >= l:
        index3 -=l
    while index4 >= l:
        index4 -=l

    x1 = line[index1]
    if x1 == '#':
        num_trees1 += 1
    x2 = line[index2]
    if x2 == '#':
        num_trees2 += 1
    x3 = line[index3]
    if x3 == '#':
        num_trees3 += 1
    x4 = line[index4]
    if x4 == '#':
        num_trees4 += 1


    index1 +=1
    index2 +=3
    index3 +=5
    index4 +=7

    if i%2 == 0:
        while index5 >= l:
            index5 -= l

        x5 = line[index5]
        if x5 == '#':
            num_trees5 += 1

        index5 +=1

print(num_trees1 * num_trees2 * num_trees3 * num_trees4 * num_trees5)
