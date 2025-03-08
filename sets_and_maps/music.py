

n = int(input())

m = int(input())
main_set = set(input().split())
for _ in range(n-1):
    _ = int(input())
    tmp_set = set(input().split())
    main_set &= tmp_set

print(len(main_set))
print(*sorted(main_set))
