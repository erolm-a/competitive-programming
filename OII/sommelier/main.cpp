#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 100
int dp[MAX];
int vini[MAX];
int N;

int calcola() {
    if(N <= 2)
        return 1;

    dp[N-1] = dp[N-2] = 1;
    int M = 0;
    for(int i = N - 3; i>=0; i--) {
        int maxDP = 0;
        for(int j = i+2; j < N; j++)
            if(vini[j] >= vini[i] && dp[j] > maxDP) maxDP = dp[j];

        dp[i] = 1 + maxDP;
        M = max(M, dp[i]);
    }
    return M;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", vini + i);
    printf("%d\n", calcola());
    return 0;
}
