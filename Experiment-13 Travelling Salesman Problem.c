#include <stdio.h>
#include <limits.h>

#define MAX 15

int n;
int cost[MAX][MAX];
int dp[1 << MAX][MAX];

int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1) {
        if (cost[pos][0] == -1)
            return INT_MAX / 2;
        return cost[pos][0];
    }

    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INT_MAX / 2;

    for (int city = 0; city < n; city++) {
        if (!(mask & (1 << city)) && cost[pos][city] != -1) {
            int next = tsp(mask | (1 << city), city);

            if (next < INT_MAX / 2) {
                int total = cost[pos][city] + next;
                if (total < ans)
                    ans = total;
            }
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            dp[mask][i] = -1;
        }
    }

    int ans = tsp(1, 0);

    if (ans >= INT_MAX / 2)
        printf("-1\n");
    else
        printf("%d\n", ans);

    return 0;
}
