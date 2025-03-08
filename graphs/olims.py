from collections import deque

class City:
    def __init__(self, t, v):
        self.t = t
        self.v = v

def main():
    n = int(input())
    indexes = deque([0])
    city_sets = []
    roads = [[] for _ in range(n)]
    prevs = [0] * n
    distances = [0] * n
    table = [(False, 0) for _ in range(n)]

    for _ in range(n):
        t, v = map(int, input().split())
        city_sets.append(City(t, v))

    for _ in range(n - 1):
        a, b, s = map(int, input().split())
        roads[a - 1].append((b - 1, s))
        roads[b - 1].append((a - 1, s))

    table[0] = (True, 0)

    while indexes:
        pos = indexes.popleft()
        table[pos] = (True, 0)

        for p, s in roads[pos]:
            if not table[p][0]:
                indexes.append(p)
                distances[p] = distances[pos] + s

                if city_sets[p].t + distances[p] / city_sets[p].v < city_sets[p].t + s / city_sets[p].v + table[pos][1]:
                    table[p] = (True, city_sets[p].t + distances[p] / city_sets[p].v)
                else:
                    table[p] = (True, city_sets[p].t + s / city_sets[p].v + table[pos][1])
                    prevs[p] = pos

    for init in range(1, n):
        distances_c = [0] * n
        table_c = [(False, 0) for _ in range(n)]
        table_c[init] = (True, 0)
        indexes.append(init)

        while indexes:
            pos = indexes.popleft()
            table_c[pos] = (True, 0)

            for p, s in roads[pos]:
                if not table_c[p][0]:
                    indexes.append(p)
                    distances_c[p] = distances_c[pos] + s

                    if city_sets[p].t + distances_c[p] / city_sets[p].v < city_sets[p].t + s / city_sets[p].v + table_c[pos][1]:
                        table_c[p] = (True, city_sets[p].t + distances_c[p] / city_sets[p].v)

                        if table_c[p][1] + table[init][1] < table[p][1]:
                            table[p] = (True, table_c[p][1] + table[init][1])
                            prevs[p] = init
                    else:
                        table_c[p] = (True, city_sets[p].t + s / city_sets[p].v + table_c[pos][1])

                        if table_c[p][1] + table[init][1] < table[p][1]:
                            table[p] = (True, table_c[p][1] + table[init][1])
                            prevs[p] = pos

            indexes.pop()

    it = max(enumerate(table), key=lambda x: x[1][1])
    print(it[1][1])

    start = it[0]
    result = [start + 1]
    
    for i in range(start, 0, -1):
        result.append(prevs[i] + 1)

    print(*result[::-1])

if __name__ == "__main__":
    main()
