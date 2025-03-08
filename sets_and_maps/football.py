import sys

goals = {}
plays = {}
teams = {}
players = {}
opens = {}
opens_players = {}

for s in sys.stdin:
    if "-" in s:
        a, b = tuple(map(lambda x: x.strip().strip(':0123456789').strip(), s.split("-")))
        score_a, score_b = tuple(map(lambda x: int(x), s.split()[-1].split(':')))
        teams[a] = teams.get(a, set())
        teams[b] = teams.get(b, set())
        goals[a] = goals.get(a, 0) + score_a
        goals[b] = goals.get(b, 0) + score_b
        plays[a] = plays.get(a, 0) + 1
        plays[b] = plays.get(b, 0) + 1
        tmp_a, tmp_b = [], []
        for i in range(score_a):
            stat = input()
            player, goal_t = ' '.join(stat.split()[:-1]), int(stat.split()[-1].strip("'"))
            teams[a].add(player)
            players[player] = players.get(player, []) + [goal_t]
            if i == 0:
                tmp_a = [player, goal_t]
        for i in range(score_b):
            stat = input()
            player, goal_t = ' '.join(stat.split()[:-1]), int(stat.split()[-1].strip("'"))
            teams[b].add(player)
            players[player] = players.get(player, []) + [goal_t]
            if i == 0:
                tmp_b = [player, goal_t]
        if (tmp_a and tmp_b and tmp_a[1] < tmp_b[1]) or (tmp_a and not tmp_b):
           opens[a] = opens.get(a, 0) + 1
           opens_players[tmp_a[0]] = opens_players.get(tmp_a[0], 0) + 1
        elif tmp_b:
           opens[b] = opens.get(b, 0) + 1
           opens_players[tmp_b[0]] = opens_players.get(tmp_b[0], 0) + 1
    elif "Total goals for" in s:
        name = s[s.index('for')+3:].strip()
        print(goals.get(name, 0))
    elif "Mean goals per game for" in s:
        name = s[s.index('for')+3:].strip()
        print(goals.get(name, 0) / plays.get(name, 1))
    elif "Total goals by" in s:
        name = s[s.index('by')+2:].strip()
        print(len(players.get(name, [])))
    elif "Mean goals per game by" in s:
        name = s[s.index('by')+2:].strip()
        n_plays = plays[next(filter(lambda t: name in t[1], teams.items()))[0]]
        print(len(players.get(name, [])) / n_plays)
    elif "Goals on minute" in s:
        minute, player = int(s.split(" by ")[0].split()[-1]), s[s.index('by')+2:].strip()
        print(len(tuple(filter(lambda x: x == minute, players.get(player, [])))))
    elif "Goals on first" in s:
        minute, player = int(s.split(" minutes by ")[0].split()[-1]), s[s.index('by')+2:].strip()
        print(len(tuple(filter(lambda x: x <= minute, players.get(player, [])))))
    elif "Goals on last" in s:
        minute, player = int(s.split(" minutes by ")[0].split()[-1]), s[s.index('by')+2:].strip()
        print(len(tuple(filter(lambda x: 91 - minute <= x, players.get(player, [])))))
    elif "Score opens by" in s:
        name = s[s.index('by')+2:].strip()
        if name in teams:
            print(opens.get(name, 0))
        else:
            print(opens_players.get(name, 0))
