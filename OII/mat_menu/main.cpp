#include <bits/stdc++.h>

using namespace std;

#define MAX_N 5000
#define MAX_B 5000
int prezzi[MAX_N+1];
int dp[MAX_N+1][MAX_B+1];
int chosen[MAX_N+1][MAX_B+1]; // indica l'oggetto scelto

int main()
{
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int N, W;
    scanf("%d %d", &N, &W);
    for(int i = 1; i <= N; i++)
        scanf("%d", prezzi + i);

    for(int i = 1; i <= N; i++) {
        for(int w = 0; w <= W; w++) {
            dp[i][w] = dp[i-1][w], chosen[i][w] = chosen[i-1][w];
            if(prezzi[i] <= w && prezzi[i] + dp[i-1][w-prezzi[i]] > dp[i][w]) {
                dp[i][w] = prezzi[i] + dp[i-1][w-prezzi[i]];
                chosen[i][w] = i;
            }
        }
    }

    for(int w = W, c = chosen[N][W]; c != 0; w -= prezzi[c], c = chosen[c-1][w])
        printf("%d\n", prezzi[c]);
}
