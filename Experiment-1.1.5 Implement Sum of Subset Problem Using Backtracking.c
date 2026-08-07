#include <stdio.h>

int arr[100];
int subset[100];
int results[1000][100];
int sizes[1000];
int count = 0;

void findSubsets(int index, int n, int target, int sum, int k) {
    if (sum == target) {
        sizes[count] = k;
        for (int i = 0; i < k; i++) {
            results[count][i] = subset[i];
        }
        count++;
        return;
    }

    if (index >= n || sum > target)
        return;

    // Include current element
    subset[k] = arr[index];
    findSubsets(index + 1, n, target, sum + arr[index], k + 1);

    // Exclude current element
    findSubsets(index + 1, n, target, sum, k);
}

int main() {
    int n, target;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &target);

    findSubsets(0, n, target, 0, 0);

    if (count == 0) {
        printf("-1\n");
    } else {
        for (int i = count - 1; i >= 0; i--) {
            for (int j = 0; j < sizes[i]; j++) {
                printf("%d ", results[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
