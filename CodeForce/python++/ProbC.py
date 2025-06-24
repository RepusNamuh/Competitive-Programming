import sys

i = 0

rating = []
for line in sys.stdin:
    if line == "\n":
        break
    if i == 0:
        N = int(line.split()[0])
        i1 = int(input())
        i2 = int(input())
    else:
        rating.append(int(line.split()[0]))
    i += 1

max_rate = max(rating)
answer = "NO"
mid_index = 2**(N - 1) - 1
mid_rate = sorted(rating)[mid_index]
friend1 = rating[i1 - 1]
friend2 = rating[i2 - 1]
if (friend1 < max_rate and friend2 < max_rate):
    answer = "NO"
elif friend1 == max_rate and friend2 >= mid_rate:
    answer = "YES"
elif friend2 == max_rate and friend1 >= mid_rate:
    answer = "YES"

print(answer)
