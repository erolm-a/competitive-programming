#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int)(1e5)
int dists[MAX_N];
vector<int> adj[MAX_N];
int N;

void bfs(int root) {
    fill(dists, dists + N, INT_MAX/4);
    queue<int> stats;
    stats.push(root);
    dists[root] = 0;
    while(!stats.empty()) {
        int v = stats.front();
        stats.pop();
        for(int w: adj[v]) if(dists[w] > dists[v] + 1) {dists[w] = dists[v] + 1; stats.push(w);}
    }
}

template<typename Int>
Int readInteger () {
    bool minus = false;
    Int result = 0;
    char ch;
    ch = getchar_unlocked();
    while (true) {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar_unlocked();
    }
    if (ch == '-') minus = true; else result = ch-'0';
    while (true) {
        ch = getchar_unlocked();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}

#define readint readInteger<int>
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    N = readint();
    for(int i = 0; i < N-1; i++)
    {
        int a, b;
        a = readint();
        b = readint();
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(0);
    bfs(max_element(dists, dists + N) - dists);
    printf("%d\n", 2**max_element(dists, dists + N));
}
