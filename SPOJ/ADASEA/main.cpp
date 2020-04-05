#include <bits/stdc++.h>

using namespace std;

int H, V;
#define MAX_N 1001
char sea[MAX_N][MAX_N+1];
#define ok(h,v) ((h) >= 0 && (h) < H && (v) >= 0 && (v) < V && sea[(h)][(v)] == '#')
#define act(h,v) if(ok(h, v)) {count++; sea[h][v] = '~'; stats.push({h, v});}

using pii = pair<int, int>;
int bfs(pii pos) {
    int count = 1;
    queue<pii> stats;
    stats.push(pos);
    int h, v; tie(h,v) = pos;
    sea[h][v] = '~';

    while(!stats.empty()) {
        tie(h, v) = stats.front();
        stats.pop();
        act(h-1, v);
        act(h, v-1);
        act(h+1, v);
        act(h, v+1);
    }
    return count;
}

int main()
{
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        scanf(" %d %d", &H, &V);
        for(int i = 0; i < H; i++)
            scanf(" %s", sea[i]);

        long long p = 0, q = H*V;
        for(int i = 0; i < H; i++)
            for(int j = 0; j < V; j++)
                if(sea[i][j] == '#') {
                    long long t = bfs({i,j});
                    p += 1ll * t*t;
                }

        long long g = p ? __gcd(p,q) : q;
        p/= g, q/= g;
        if(q==1) printf("%lld\n", p);
        else printf("%lld / %lld\n", p, q);
    }
}
