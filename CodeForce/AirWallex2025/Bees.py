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

bees = sorted(bees)
set_bees = list(set(bees))

mid = (N + K) // 2 - 1

previous = set_bees[set_bees.index(bees[mid]) - 1]
mid_num = (previous + bees[mid]) // 2

if (N + K) % 2 == 0:
    if bees[mid] != bees[mid + 1]:
        print(bees[mid])
    else:
        print(mid_num if (mid_num != bees[mid]) else previous)
else:
    another_mid = (bees[mid] + bees[mid + 1]) // 2
    if bees[mid] != bees[mid + 1]:
        print(another_mid if (another_mid != bees[mid]) else bees[mid])
    else:
        print(mid_num if (mid_num != bees[mid]) else previous)

# [a, b, c, d, e, f, g] 7 3 choose e 
# [a, b, c, d, e, e, g] 7 3 choose d if (d + e) / 2 != e

# [a, b, c, d, e, f, g, h] 8 3 choose e if (e + f) / 2 != e
# [a, b, c, d, e, e, g, h] 8 3 choose d if (d + e)  / 2 != e

# [a, b, c, d, e, f, g] 7 2 Choose d if (d + e) / 2 != e
# [a, b, c, d, d, f, g] 7 2 choose c if (c + d) / 2 != d

# [a, b, c, d, e, f, g, h] 8 2 Choose e
# [a, b, c, d, e, e, g, h] 8 2 choose d if (d + e) / 2 != e


