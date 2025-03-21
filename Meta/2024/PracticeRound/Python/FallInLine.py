import sys
from collections import defaultdict
import random

i = 1
def grad_intercept(x1, y1, x2, y2):
    try: 
        a = float((y2 - y1) / (x2 - x1))
        b = 1.0
    except ZeroDivisionError:
        a = 1.0
        b = 0.0
    c = b * y1 - a * x1
    return (a, c, b)

with open("Meta\\2024\\PracticeRound\\input\\fall_in_line_input.txt", "r") as f:
        lines = list(map(str.strip, f.readlines()))

no_test = int(lines[0])
count = 1
while count <= no_test:
    no_ant = int(lines[i])
    coor_list = []
    max_ant = 0

    for j in range(i + 1, i + no_ant + 1):
        x, y = list(map(float, lines[j].split()))
        coor_list.append((x, y))

    #trials = round(0.75 * no_ant)

    for _ in range(40):
        j = random.randint(0, no_ant - 1)
        k = random.randint(0, no_ant - 1)
        x1, y1 = coor_list[j]
        x, y = coor_list[k]
        a, c, b = grad_intercept(x1, y1, x, y)
        score = 0
        for x, y in coor_list:
            if round(a * x + c) == b*y:
                score+= 1
        max_ant = max(score, max_ant)

    with open("Meta\\2024\\PracticeRound\\output.txt", "a") as f:
        f.write(f"Case #{count}: {no_ant - max_ant}\n")
    i += no_ant + 1
    count += 1
