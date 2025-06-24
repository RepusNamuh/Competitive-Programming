import sys

i = 0

for line in sys.stdin:
    if line == "\n":
        break
    elif i == 0:
        N, M = map(int, line.split())
    else:
        p1, p2 = map(int, line.split())
    i += 1