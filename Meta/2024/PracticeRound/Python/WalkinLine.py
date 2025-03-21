import sys

i = 0
for line in sys.stdin:
    if line == "\n":
        break
    if i == 0:
        no_test = line
    else:
        N, K = list(map(int, line.split()))
        A = []
        while True:
            if len(A) == N:
                break
            A.append(int(input()))
        smallest = sorted(A)[0]
        max_run = ((2 *N - 3) * smallest) if len(A) > 2 else smallest
        with open("Meta\\output.txt", "a") as f:
            f.write(f"Case #{i}: {"YES" if max_run <= K else "NO"}\n")
        
    i += 1
