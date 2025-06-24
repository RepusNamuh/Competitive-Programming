import sys

i = 0
for line in sys.stdin:
    if line == "\n":
        break
    if i == 0:
        N, K = list(map(int, line.split()))
    else:
        stack = list(map(int, line.split()))[::-1]
    i += 1

total = 0
cut_off = 0
temp = stack[:]
for i, item in enumerate(temp):
    if i == 0:
        total += item
    else:
        normal_lift = sum(stack[:i - cut_off])
        if normal_lift <= K:
            total += normal_lift + item
        else:
            stack = stack[i - cut_off:]
            cut_off = i
            total += item + K


print(total)