import sys

i = 0
bricks = {}
for line in sys.stdin:
    if line == "\n":
        break
    if i == 0:
        N = int(line.split()[0])
    else:
        width, height = list(map(int, line.split()))
        if width not in bricks:
            bricks[width] = height
        bricks[width] = max(bricks[width], height)
    i += 1


print(sum(bricks.values()))

