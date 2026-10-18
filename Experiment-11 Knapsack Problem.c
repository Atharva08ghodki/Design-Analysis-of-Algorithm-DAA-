#include <stdio.h>

int main() {
    int n, W, i, w;
    scanf("%d", &n);

    int value[n], weight[n];

    for (i = 0; i < n; i++)
        scanf("%d", &value[i]);

    for (i = 0; i < n; i++)
        scanf("%d", &weight[i]);

    scanf("%d", &W);

    int dp[n + 1][W + 1];

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weight[i - 1] <= w) {
                int include = value[i - 1] + dp[i - 1][w - weight[i - 1]];
                int exclude = dp[i - 1][w];
                dp[i][w] = (include > exclude) ? include : exclude;
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    printf("%d\n", dp[n][W]);

    return 0;
}
