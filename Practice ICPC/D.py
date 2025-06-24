import sys

i = 0

for line in sys.stdin:
    if line == "\n":
        break
    elif i == 0:
        N = int(line.split()[0])
    else:
        keys = list(map(int, line.split()))
    i += 1

total = 1e9

for i in range(N):
    temp = 0
    for j in range(N):
        if i == j:
            continue
        if j < i:
            temp += abs(keys[i] - i+ j - keys[j])
        else:
            temp += abs(keys[i] + j - i - keys[j])
    total = min(temp, total)
print(total)

