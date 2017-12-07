#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100000
#define N_LOG 20

int parent[MAX_N];
int adv[MAX_N][N_LOG];
int skip_brig[MAX_N][N_LOG];
int depth[MAX_N];
vector<int> adj[MAX_N];
static int *briganti;
int limit;

int proceed(int &v, int step)
{
    // facciamo Fenwick-like

    int ans = 0;

    while(step) {
        int i = __builtin_ctz(step);
        step -= 1 << i;
        ans = max(ans, skip_brig[v][i]);
        v = adv[v][i];
    }
    return ans;
}

int findlca(int a, int b)
{
    int p_a = briganti[a], p_b = briganti[b];
    if(depth[a] < depth[b])
        p_b = proceed(b, depth[b] - depth[a]);
    else if(depth[b] < depth[a])
        p_a = proceed(a, depth[a] - depth[b]);
    int step = limit;
    while(b != a)
    {
        if(adv[a][step] != adv[b][step] || step == 0)
            p_a = max(p_a, proceed(a, 1 << step)),
            p_b = max(p_b, proceed(b, 1 << step));
        else step--;
    }
    return max(p_a, p_b);
}

void dfs(int r)
{
    adv[r][0] = parent[r];
    skip_brig[r][0] = max(briganti[r], briganti[parent[r]]);
    if(r > 0)
        for(int i = 1; i <= limit; i++) {
            adv[r][i] = adv[adv[r][i-1]][i-1];
            skip_brig[r][i] = max(skip_brig[r][i-1], skip_brig[adv[r][i-1]][i-1]);
        }
    for(int v: adj[r])
        if(parent[v] < 0) {
            parent[v] = r;
            depth[v] = depth[r]+1;
            dfs(v);
        }
}

void solve(int N, int Q, int *briganti, int *A, int *B, int *start, int *end, int *sol)
{
    ::briganti = briganti;
    for(int i = 0; i < N-1; i++) {
        adj[A[i]].push_back(B[i]);
        adj[B[i]].push_back(A[i]);
    }
    limit = 8*sizeof(int) - __builtin_clz(N);
    fill(parent + 1, parent + N, -1);
    fill(adv[0], adv[0] + N_LOG, 0);
    dfs(0);
    for(int i = 0; i < Q; i++)
        sol[i] = findlca(start[i], end[i]);
}
