#include <bits/stdc++.h>

using namespace std;

enum direzione {
    SX = 0, DX = 1
};
#define MAX_N 2000000

struct dp_t {
    int val;
    direzione dir;
    int tree;
} dp[MAX_N+1];

void Abbatti(int indice, int direzione);

static int* H;
static int N;

int dsx[MAX_N], ddx[MAX_N], beaten[MAX_N], best[MAX_N];

void init()
{
    for(int i = 0; i < N; i++) {
        dsx[i] = i; beaten[i] = INT_MAX;
        while(dsx[i] > 0 && dsx[i]> i - H[i] +1) {
            beaten[dsx[i]-1] = i;
            dsx[i] = dsx[dsx[i]-1];
        }
    }

    for(int i = N-1; i >= 0; i--) {
        ddx[i] = i;
        while(ddx[i] < N - 1 && ddx[i] < i + H[i] - 1)
            ddx[i] = ddx[ddx[i]+1];
    }
}

inline void migliore(int i)
{
    int ris = i;
    if(beaten[i] != INT_MAX && dp[i+1].val > dp[best[beaten[i]]+1].val)
        ris = best[beaten[i]];
    best[i] = ris;
}

inline void down(int i)
{
    dp[i] = {dp[ddx[i]+1].val+1, DX, i};

    int j = best[i];
    if(dp[i].val > dp[j+1].val+1)
        dp[i] = {dp[j+1].val+1, SX, j};
}

void Pianifica(int N, int altezza[])
{
    ::H = altezza;
    ::N = N;
    init();
    for(int i = N-1; i >= 0; i--) {migliore(i); down(i);}

    // ricostruiamo la soluzione
    int i = 0;
    for(int c = dp[0].val; c > 0; c--)
    {
        Abbatti(dp[i].tree, static_cast<int>(dp[i].dir));
        if(dp[i].dir == SX)
            i = dp[i].tree+1;
        else i = ddx[i]+1;
    }
}
