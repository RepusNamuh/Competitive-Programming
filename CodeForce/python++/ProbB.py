import sys
from collections import Counter
i = 0

assignments = []
for line in sys.stdin:
    if line == "\n":
        break
    if i == 0:
        N, K = list(map(int, line.split()))
    else:
        assignments.append(int(line.split()[0]))
    i += 1

juggle = [1] * (N)
K = 10 if K % 2 == 0 else 11
for i in range(K):
    temp = [0] * N
    for j in range(N):
        temp[assignments[j] - 1] += juggle[j]
    juggle = temp[:]

max_val = max(juggle)
print(juggle.index(max_val) + 1, max_val)

