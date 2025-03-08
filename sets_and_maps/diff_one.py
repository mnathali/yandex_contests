from collections import Counter

n = int(input())

counter = Counter([int(x) for x in input().split()])
max = 0

for el in counter:
    if counter[el] + counter[el-1] > max:
        max = counter[el] + counter[el-1]
    if counter[el] + counter[el+1] > max:
        max = counter[el] + counter[el+1]

print(n-max)