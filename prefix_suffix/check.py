

n = int(input())
lst = [int(x) for x in input().split()]

sm = 0
for i in range(n):
    print(i)
    for j in range(i+1, n):
        for k in range(j+1, n):
            sm = sm + lst[i]*lst[j]*lst[k]
            print('j = ', j)

print(sm % 1000000007)