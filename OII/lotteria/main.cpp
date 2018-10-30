#include <bits/stdc++.h>

using namespace std;

#define MAX_N 20
#define MAX_M 200000
#define MODULO 1000000007
int dp[MAX_N+1][MAX_M];

int m, n;
int main()
{
    scanf("%d %d", &n, &m);

    int sum = 0;
    if(m >= 1<<(n-1)) {
        fill(dp[0]+1,dp[0]+m+1,1);
        for(int i = 1; i < n; i++) {
            dp[i][1<<i] = 1;
            for(int j = (1<<i)+1; j <= m; j++)
                // trick: il secondo addendo solo se j è pari
                dp[i][j] = (dp[i][j-1] + (!(j%2))*dp[i-1][j/2]) % MODULO;
        }

        for(int i = 1<<(n-1); i <=m; i++)
            sum = (sum + dp[n-1][i]) % MODULO;
    }

    printf("%d\n", sum);
}
