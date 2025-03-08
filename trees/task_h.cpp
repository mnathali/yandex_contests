#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

void dfs(int u, const std::vector<std::vector<int>> &tree, const std::vector<int> &weights, 
         std::vector<std::pair<unsigned long long, unsigned long long>> &dp, 
         std::vector<bool> &visited) 
{
    visited[u] = true;
    dp[u].second = weights[u];
    dp[u].first = 0;

    for (int v : tree[u]) {
        if (!visited[v]) {
            dfs(v, tree, weights, dp, visited);

            dp[u].second += std::min(dp[v].first, dp[v].second);

            dp[u].first += dp[v].second;

        }
    }
}

void find_painted(int u, bool isParentPainted, const std::vector<std::vector<int>> &tree, 
         std::vector<std::pair<unsigned long long, unsigned long long>> &dp, 
         std::vector<bool> &visited, std::vector<bool> &draw) {
    visited[u] = true;

    if (!isParentPainted || dp[u].second <= dp[u].first) {
        draw[u] = true;
        isParentPainted = true;
    } else {
        draw[u] = false;
        isParentPainted = false;
    }

    for (int v : tree[u]) {
        if (!visited[v]) {
            find_painted(v, isParentPainted, tree, dp, visited, draw);
        }
    }
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> tree(n);
    std::vector<int> weights(n);
    std::vector<bool> draw(n, false);
    std::vector<std::pair<unsigned long long, unsigned long long>> dp(n);
    std::vector<bool> visited(n, false);

    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        std::cin >> a >> b;
        tree[a - 1].push_back(b - 1);
        tree[b - 1].push_back(a - 1);
    }

    for (int i = 0; i < n; ++i) {
        std::cin >> weights[i];
    }

    dfs(0, tree, weights, dp, visited);
    visited.assign(n, false);
    find_painted(0, true, tree, dp, visited, draw);
    unsigned long long minWeight = std::min(dp[0].first, dp[0].second);

    int paintedCount = 0;
    for (int i = 0; i < n; ++i) {
        if (draw[i]) {
            ++paintedCount;
        }
    }
    if (n == 1)
    {
        draw[0] = true;
        minWeight = weights[0];
        paintedCount = 1;
    }
    std::cout << minWeight << " " << paintedCount << std::endl;
    for (int i = 0; i < n; ++i) {
        if (draw[i]) {
            std::cout << i + 1 << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
