n = int(input())
m = 0
i = 0
j = 0
total = 0

while total < n + 1:
    sq = i * i
    qr = j * j * j
    m = min(sq, qr)
    
    if sq == qr:
        i += 1
        j += 1
    elif sq > qr:
        j += 1
    else:
        i += 1
    
    total += 1

print(m)
