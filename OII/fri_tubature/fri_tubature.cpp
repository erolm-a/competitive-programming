#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100000

struct centrale{
    int citta;
    int guardie;
}centrali[MAX_N];

vector<centrale*> adj[MAX_N];
int inner[MAX_N];

int N, M;

bitset<MAX_N> cities_subtree;

void cities_down_there(centrale* root)
{
    if(root->citta)
    {
        cities_subtree[root - centrali] = true;
        return;
    }
    bool ok = false;
    for(centrale* p: adj[root-centrali])
    {
        cities_down_there(p);
        if(cities_subtree[p - centrali])
            ok = true;
    }
    cities_subtree[root - centrali] = ok;
}

int dfs(centrale* root)
{
    int sum = 0;
    if(adj[root-centrali].size() == 0 || root->citta)
        return root->guardie;


    for(centrale* i: adj[root - centrali])
        if(cities_subtree[i - centrali])
            sum += dfs(i);

    return min(sum , root->guardie);
}

int pianifica(int N, int M, int da[], int a[], int C[], int G[])
{
    ::N = N, ::M = M;

    for(int i = 0; i < N-1; i++) {
        adj[da[i]].push_back(centrali + a[i]);
        inner[a[i]]++;
        centrali[i].guardie = G[i];
    }
    for(int i = 0; i < M; i++)
        centrali[C[i]].citta++;

    auto root = centrali + (find(inner, inner + N, 0) - inner);

    cities_down_there(root);

    return dfs(root);
}
