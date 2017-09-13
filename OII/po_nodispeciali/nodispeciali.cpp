#include <bits/stdc++.h>

#define MAX_N 1000001

using namespace std;
using ll = long long;

int N, K;
bitset<MAX_N> is_filiale;

int filiali_to[MAX_N];
ll dists[MAX_N];

int* filiali;
using pii = pair<int, ll>;
vector<pii> adj[MAX_N];
// diametro
pii parent[MAX_N];
ll max_dist = 0, max_pos;

bitset<MAX_N> visited;
int dfs(int v)
{
    filiali_to[v] = (int) is_filiale[v];

    visited[v] = true;
    for(pii w: adj[v])
        if(!visited[w.first]) {
            parent[w.first] = {v, w.second};
            dists[w.first] = w.second + dists[v],
                    filiali_to[v] += dfs(w.first);
            if(dists[w.first] > max_dist)
                max_pos = w.first, max_dist = dists[w.first];
        }
    return filiali_to[v];
}

int calcola()
{
    ll sum = 0;
    vector<pii> diametro;
    pii p = {max_pos, 0};
    while(p.first > 0)
    {
        diametro.push_back(p);
        p = parent[p.first];
    }

    // p è un estremo del diametro - si può togliere
    p = diametro.back();
    diametro.pop_back();
    for(int i = 0; i < K; i++)
        sum += dists[filiali[i]];
    ll min_sum = sum, best = p.first;

    ll prec = p.second;


    // bene... dobbiamo prendere i successivi
    while(!diametro.empty())
    {
        p = diametro.back();
        diametro.pop_back();
        sum = sum - prec*filiali_to[p.first] + prec*(K - filiali_to[p.first]);
        if(min_sum > sum)
            min_sum = sum, best = p.first;
        prec = p.second;
    }
    return best;
}

int trova_sede(int N, int K, int A[], int B[], int P[], int filiali[])
{
    ::N = N, ::K = K;
    if(N == 1) return 1;
    for(int i = 0; i < N-1; i++) {
        adj[A[i]].emplace_back(B[i], P[i]);
        adj[B[i]].emplace_back(A[i], P[i]);
    }
    ::filiali = filiali;
    for(int i = 0; i < K; i++)
        is_filiale[filiali[i]] = true;

    // troviamo il diametro
    dfs(1);
    visited.reset();
    for(int i = 1; i <= N; i++)
        dists[i] = 0,
       parent[i] = {0, 0};
    max_dist = 0;

    dfs(max_pos);
    return calcola();
}
