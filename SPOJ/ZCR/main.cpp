#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_N 1001
#define MAX_K 1000

//dp[i][j]: qual è la probabilità avendo i monete, di cui j devono dare testa
double dp[MAX_N][MAX_K], P[MAX_N];

int N, K;

void calcola()
{
    dp[0][0] = 1.;
    for(int i = 1; i <= N; i++) {
        dp[i][0] = (1. - P[i]) * dp[i-1][0];
        for(int j = 1; j <= min(i,K); j++)
            dp[i][j] = P[i]*dp[i-1][j-1] + (1-P[i])*dp[i-1][j];
    }
}


int main()
{
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d %d", &N, &K);
        for(int i = 0; i < N; i++)
            scanf("%lf", P + i);
        calcola();
        printf("%.10f\n", dp[N][K]);
    }
}
