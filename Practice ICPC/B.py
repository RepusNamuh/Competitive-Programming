import sys

i = 0
Okay = True
books = []
for line in sys.stdin:
    if line == "\n":
        break
    if i == 0:
        N, H = map(int, line.split())
    else:
        l, w, h = map(int, line.split())
        if all(size > H for size in (l, w, h)):
            Okay = False
            break
        l1, w1, h1 = 0, 0, 0
        if l <= H and l > h1:
            h1 = l
            l1 = max(w, h)
            w1 = min(w, h)
        if h1< w <= H:
            h1 = w
            l1 = max(l, h)
            w1 = min(l, h)
        if h <= H and h > h1:
            h1 = h
            l1 = max(l, w)
            w1 = min(l, w)
        books.append((l1, w1, h1))

    i += 1

def min_width(books, Okay):
    if not Okay:
        return "Impossible"
    require_width = 0   
    for (l, w, h) in books:
        require_width += w

    return require_width

print(min_width(books, Okay))
    