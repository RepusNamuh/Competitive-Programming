import sys

i = 0

bees = []
for line in sys.stdin:
    if line == "\n":
        break
    if i == 0:
        N, K = list(map(int, line.split()))
    else:
        bees.append(int(line.split()[0]))
    i += 1

bees.sort()

mid = (N + K) // 2 - 1

if bees[mid] != bees[mid + 1]:
        print(bees[mid + 1] - 1)
else:
    print(bees[mid] - 1)





