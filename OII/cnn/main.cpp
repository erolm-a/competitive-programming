#include <bits/stdc++.h>

#define MAX_N 1001

struct {
    int min_cost; bool same;
} dp[MAX_N][MAX_N][2];

bool vis[MAX_N][MAX_N][2];
int R[MAX_N], C[MAX_N];
int N;

constexpr bool row{false}, col{true};

int f(int n, int u, bool s) {
    if(n == N) return 0;
    if(vis[n][u][s]) return dp[n][u][s].min_cost;
    vis[n][u][s] = true;
    int with_r, with_c;

    if(n == 0) {
        with_r = R[0] - 1 + f(1,1, row), with_c = C[0] - 1 + f(1,1,col);
        if(with_r < with_c)
            dp[0][0][0] = {with_r, row};
        else dp[0][0][0] = {with_c, col};
        return dp[0][0][0].min_cost;
    }

    int r = (s == row ? R[n-1] : u), c = (s == col ? C[n-1] : u);
    with_r = abs(R[n] - r) + f(n+1, c, row), with_c = abs(C[n] - c) + f(n+1, r, col);
    if(with_r < with_c) dp[n][u][s] = {with_r, s == row};
    else dp[n][u][s] = {with_c, s == col};
    return dp[n][u][s].min_cost;
}

template<typename Int>
Int readInteger () {
    Int result = 0;
    char ch;
    ch = getchar_unlocked();
    while (true) {
        if (ch >= '0' && ch <= '9') break;
        ch = getchar_unlocked();
    }
    result = ch-'0';
    while (true) {
        ch = getchar_unlocked();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    return result;
}

void print(bool pos){printf("%c\n","CR"[pos==row]);}
#define readint readInteger<int>
int main()
{
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    N = readint();
    (void) readint(); // il parametro M è in fin dei conti inutile

    for(int i = 0; i < N; i++) { R[i] = readint(); C[i] = readint(); }

    f(0,0,0);
    bool pos = dp[0][0][0].same;
    print(pos);
    for(int i = 1, u = 1; i < N; i++) {
        auto x = dp[i][u][pos].same;
        if(!x) {
            pos ^= true;
            if (pos == row) u = C[i-1];
            else u = R[i-1];
        }
        print(pos);
    }
}
