dat = open('input1.txt', 'r')
sez = list(map(lambda x: int(x.strip('\n')), dat.readlines()))

#sez = [1721, 979, 366, 299, 675, 1456]

# Part one
found = False
for x in sez:
    for y in sez[1:]:
        if x + y == 2020:
            found = True
            print(x * y)
            break
    if found:
        break


#part two
found = False
for x in sez:
    for y in sez[1:]:
        for z in sez[2:]:
            if x + y + z == 2020:
                found = True
                print(x * y * z)
                break
        if found:
            break
    if found:
        break
