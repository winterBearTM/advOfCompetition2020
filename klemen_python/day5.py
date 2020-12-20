import time
text_file = open("inputs/input_d5.txt", "r")
lines = text_file.readlines()
text_file.close()

print("Read {} boarding pass lines.".format(len(lines)))

zeros = [ [0] * 8 for _ in range(128)]

vals = [64,32,16,8,4,2,1]
colvals = [8,4,2,1]
for line in lines:    
    rowCode=line[:6]
    colCode=line[7:10]
    rowval=0
    for i in range(len(line)):
        if line[i] == 'F':
            rowval = rowval + vals[i]
        else:
            pass

    colval=0
    for i in range(len(line)):
        if line[i] == 'R':
            colval = colval + colvals[i]
        else:
            pass
    print(rowval)
    print(colval)
    print(rowCode)
    print(colCode)