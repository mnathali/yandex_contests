
def closure_b(i):
    def inner(nr):
        return (nr[0], '0') if nr[1] == '*' and (nr[0] % 8 - (nr[0] - i) // 8 == i % 8 and nr[0] > i
            or nr[0] % 8 + (i - nr[0]) // 8 == i % 8 and nr[0] < i
            or nr[0] % 8 - (i - nr[0] + (i//8-nr[0]//8)) // 8 == i % 8 and nr[0] < i
            or nr[0] % 8 + (nr[0] - i + (nr[0]//8 - i//8)) // 8 == i % 8 and nr[0] > i
            ) else nr
    return inner

def closure_r(i):
    def inner(nr):
        return (nr[0], '0') if nr[1] == '*' and (nr[0] % 8 == i % 8 or nr[0] // 8 == i // 8) and nr[0] != i else nr
    return inner

res = list(''.join([input()[:8] for _ in range(8)]))

n = len(res)

s = enumerate(res)

for i in range(n):
    if res[i] == 'R':
        s = map(closure_r(i), s)
    elif res[i] == 'B':
        s = map(closure_b(i), s)

s = list(map(lambda x: x[1], s))
print(s.count('*'))
s = [''.join(s[8 * i: 8 * (i+1)]) for i in range(8)]
print(*s, sep='\n')