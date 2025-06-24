import sys
from functools import lru_cache

# Read all input at once
i = 0
G = {}
for line in sys.stdin:
    if line == "\n":
        break
    if i == 0:
        N, M = list(map(int, line.split()))
    else:
        parent, child = map(int, line.split())
        if parent == child:
            # Self-loop, immediately invalid
            print(-1)
            sys.exit(0)
            G.setdefault(parent, []).append(child)


# Get all nodes (including ones with no outgoing edges)
all_nodes = set(G.keys())
for children in G.values():
    all_nodes.update(children)

# Memoized DFS

@lru_cache(maxsize=None)
def dfs(node, visited=frozenset()):
    if node in visited:
        return 0  # Cycle detected

    max_len = 1  # At least the node itself
    for neighbor in G.get(node, []):
        path_len = dfs(neighbor, visited | {node})
        if path_len == 0:
            return 0  # Propagate cycle
        max_len = max(max_len, 1 + path_len)
    return max_len

# Find the maximum path length
result = 0
for node in all_nodes:
    path_len = dfs(node)
    if path_len == 0:
        print(-1)
        sys.exit(0)
    result = max(result, path_len)

print(result)
