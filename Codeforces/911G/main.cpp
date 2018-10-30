#include <bits/stdc++.h>

using namespace std;

#define MAX_N 200000

int N;
int stree[4*MAX_N][101];
vector<pair<int, int>> lazy[4*MAX_N];

inline void join(int v1[101], int v2[101], int v3[101]) {
    for(int i = 1; i<=100; i++)
        v3[i] = v1[i] + v2[i];
}

inline void setwhere(int set, int where, int root) {
    stree[root][set]+=stree[root][where], stree[root][where] = 0;
}

#define sx(i) i*2
#define dx(i) i*2+1

int numbers[MAX_N];

void build(int l, int r, int root=1) {
    static int idx = 0;
    if(r - l == 0) {
        stree[root][numbers[idx++]] = 1;
        return;
    }
    int m = (l + r)/2;
    build(l, m, sx(root));
    build(m+1, r, dx(root));
    join(stree[sx(root)], stree[dx(root)], stree[root]);

}

void update(int l, int r, int start, int end, int set, int where, int root=1) {
    for(auto p: lazy[root]) {
        int s = p.first, w = p.second;
        setwhere(s, w, root);
        if(r - l) {
            lazy[dx(root)].push_back(p);
            lazy[sx(root)].push_back(p);
        }
    }
    lazy[root].clear();

    if(r < start || end < l)
        return;
    if(start <= l && r <= end) {
        setwhere(set, where, root);
        if(r - l) {
            lazy[dx(root)].push_back({set, where});
            lazy[sx(root)].push_back({set, where});
        }
        return;
    }
    int m = (l + r)/2;
    update(l, m, start, end, set, sx(root));
    update(m+1, r, start, end, set, dx(root));
    join(stree[dx(root)], stree[sx(root)], stree[root]);
}


void query(int l, int r, int root = 1)
{
    for(auto p: lazy[root]) {
        int s = p.first, w = p.second;
        setwhere(s, w, root);
        if(r - l) {
            lazy[dx(root)].push_back(p);
            lazy[sx(root)].push_back(p);
        }
    }
    lazy[root].clear();

    if(l == r)
        for(int i = 1; i <= 100; i++)
            if(stree[root][i]) {cout << i << ' '; return;}

    int m = (l + r)/2;

    query(l, m, sx(root));
    query(m+1, r, dx(root));
}

int main()
{
    ios_base::sync_with_stdio(false);

    int N, Q;
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> numbers[i];
    build(1, N);
    cin >> Q;

    for(int i = 0; i < Q; i++)
    {
        int a, b, w, s;
        cin >> a >> b >> w >> s;
        update(1, N, a, b, s, w);
    }
    query(1, N);
}
