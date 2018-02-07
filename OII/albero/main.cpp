#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100001
int N;
vector<int> adj[MAX_N], rev[MAX_N];

vector<int> sols; int best = INT_MAX;

bitset<MAX_N> visited;

int dfs(int v) {
    visited[v] = true;
    int count = 0;
    for(int w: adj[v])
        if(!visited[w])
            count += dfs(w);
    for(int w: rev[v])
        if(!visited[w])
            count += 1 + dfs(w);
    return count;
}

void dfs2(int v, int ris) {
    visited[v] = true;
    if(ris < best) {
        best = ris;
        sols.clear();
    }
    if(ris == best) sols.push_back(v);
    for(int w: adj[v])
        if(!visited[w])
            dfs2(w, ris+1);
    for(int w: rev[v])
        if(!visited[w])
            dfs2(w, ris-1);
}

int main()
{
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d", &N);
    for(int i = 0; i < N-1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        rev[b].push_back(a);
    }
    best = dfs(1);
    sols.push_back(1);
    visited.reset();
    dfs2(1, best);

    printf("%d\n", best);
    sort(sols.begin(), sols.end());
    for(int i: sols)
        printf("%d ", i);
}
