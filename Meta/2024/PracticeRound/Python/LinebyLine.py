import sys
from math import pow
i = 0
for line in sys.stdin:
    if line == "\n":
        break
    if i == 0:
        no_test = line
    else:
        N, P = list(map(float, line.split()))
        Prob = P * (pow((100/P), 1/N) - 1)
        with open("Meta\\2024\\PracticeRound\\output.txt", "a") as f:
            f.write(f"Case #{i}: {Prob}\n")
    i += 1