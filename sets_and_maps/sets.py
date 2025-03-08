n = int(input())
s1 = set([int(x) for x in input().split()])
m = int(input())
s2 = set([int(x) for x in input().split()])
k = int(input())
s3 = set([int(x) for x in input().split()])

print(*sorted((s1 & s2) | (s2 & s3) | (s1 & s3)))