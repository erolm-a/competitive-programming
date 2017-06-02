#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_N 10
int discesa[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j <= i; j++)
            scanf("%d", &discesa[i][j]);

    dp[0][0] = discesa[0][0];
    if(N > 1) {
        dp[1][0] = discesa[0][0] + discesa[1][0];
        dp[1][1] = discesa[0][0] + discesa[1][1];

        for(int i = 2; i < N; i++) {
            dp[i][0] = dp[i-1][0] + discesa[i][0];
            dp[i][i] = dp[i-1][i-1] + discesa[i][i];

            for(int j = 1; j < i; j++)
                dp[i][j] = discesa[i][j] + max(dp[i-1][j-1], dp[i-1][j]);
        }
    }

    printf("%d\n", *max_element(dp[N-1], dp[N-1] + N));

    return 0;
}
