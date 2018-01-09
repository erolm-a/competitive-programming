#include <cstdio>

using namespace std;

#define MAX_M 1000
char S[MAX_M+1];
int dp[MAX_M+1][MAX_M+1];
int state[MAX_M+1][2];

int N, M;

int risolvi(int n, int s) {
    int& r = dp[n][s];
    if(r > 0) return r;
    if(s == M) return 0;
    if(n == N) return r = 1;
    r = (risolvi(n+1, state[s][0]) + risolvi(n+1, state[s][1])) % 2011;
    return r;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d %d %s", &M, &N, S);
    state[0][S[0]-'0'] = 1;

    for(int i = 1, lps = 0; i < M; i++) {
        state[i][0] = state[lps][0], state[i][1] = state[lps][1];
        state[i][S[i]-'0'] = i+1;
        lps = state[lps][S[i]-'0'];
    }

    printf("%d\n", risolvi(0, 0));
}
