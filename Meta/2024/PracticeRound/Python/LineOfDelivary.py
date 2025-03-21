import sys
from collections import defaultdict
import random
import math


with open("Meta\\2024\\PracticeRound\\input\\sample.txt", "r") as f:
        lines = list(map(str.strip, f.readlines()))

i = 1
no_test = int(lines[0])
count = 1
while count <= no_test:
        N, G = list(map(int, lines[i].split()))
        stone_list = []
        for j in range(i + 1, i + N + 1):
                stone_list.append(int(lines[j]))

        stone_list = sorted(stone_list, reverse=True)
        closest_index = 0
        smallest_diff = math.inf
        for j, stone in enumerate(stone_list):
                current_diff = abs(stone - G)
                if current_diff < smallest_diff:
                        smallest_diff = current_diff
                        closest_index = j + 1
                
        with open("Meta\\2024\\PracticeRound\\output.txt", "a") as f:
            f.write(f"Case #{count}: {closest_index} {smallest_diff}\n")
        count += 1
        i += N + 1