import sys

i = 0
for line in sys.stdin:
    if line == "\n":
        break
    if i == 0:
        T = list(map(int, line.splitlines()))
    else:
        no_num = {0: 3, 1: 1, 2: 2, 3:1, 5:1}
        n = int(line.split()[0])
        num_list = list(map(int, input().split()))
        Done = False
        for j, num in enumerate(num_list):
            if num in no_num and no_num[num] > 0:
                no_num[num] -= 1

            if all(value == 0 for value in no_num.values()):
                Done = True
                break
        if Done:
            print(j + 1)
        else:
            print(0)
    i += 1