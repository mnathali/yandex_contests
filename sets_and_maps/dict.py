st = set(input().split())

d = {}
lst = input().split()
for w in range(len(lst)):
    if lst[w] in d:
        lst[w] = d[lst[w]]
    else:
        for i in range(1, len(lst[w])):
            if lst[w][0:i] in st:
                d[lst[w]] = lst[w][0:i]
                lst[w] = lst[w][0:i]
                break
print(*lst)