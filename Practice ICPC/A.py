import sys

graph = {}
i = 0
for line in sys.stdin:
    if line == '\n':
        break
    elif i == 0:
        N, M = map(int, line.split())
    else:
        p1, p2 = map(int, line.split())
        if p1 not in graph:
            graph[p1] = []
        if p2 not in graph:
            graph[p2] = []
        graph[p1].append(p2)
        graph[p2].append(p1)
        pass
    i += 1


print(M) if M > 0 else print(1)