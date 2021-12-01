#part one
count = 0
for line in open('input2.txt', 'r'):
    data = line.split(' ')
    interval = data[0].split('-')
    a = int(interval[0])
    b = int(interval[1])
    letter = data[1].strip(':')
    password = data[2]

    letter_count = password.count(letter)

    if letter_count >= a and letter_count <= b:
        count += 1

print(count)

#part two
count = 0
for line in open('input2.txt', 'r'):
    data = line.split(' ')
    interval = data[0].split('-')
    a = int(interval[0])
    b = int(interval[1])
    letter = data[1].strip(':')
    password = data[2]

    if (password[a-1]  == letter) != (password[b-1] == letter):
        count += 1

print(count)
