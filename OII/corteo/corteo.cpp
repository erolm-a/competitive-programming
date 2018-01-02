#include <bits/stdc++.h>

#define MAX_N 1000
int dists[MAX_N][MAX_N];

using namespace std;
vector<int> adj[MAX_N];

int N, M;

int D[2], P[2];

void sposta(int chi, int dove);

void bfs(int v)
{
    queue<int> states;
    states.push(v);
    dists[v][v] = 0;

    while(!states.empty())
    {
        int p = states.front();
        states.pop();

        for(int i: adj[p])
            if(dists[v][i] > dists[v][p]+1) {
                dists[v][i] = dists[v][p]+1;
                states.push(i);
            }
    }
}

bitset<MAX_N> stati[MAX_N];
//vector<pair<int, int>> spostamenti;
bool possible(int threshold)
{
    queue<pair<int, int>> mosse;
    for(int i = 0; i<N; i++)
        stati[i].reset();

    int c0 = P[0], c1 = P[1];

    mosse.push({c0,c1});

    stati[c0][c1] = true;
    while(!mosse.empty()) {
        c0 = mosse.front().first, c1 = mosse.front().second;
        mosse.pop();
        if(c0 == D[0] && c1 == D[1]) { return true; }

        for(int w: adj[c0])
            if(dists[w][c1] >= threshold && !stati[w][c1]) {
                stati[w][c1] = true;
                mosse.push({w, c1});
            }

        for(int w: adj[c1])
            if(dists[c0][w] >= threshold && !stati[c0][w]) {
                stati[c0][w] = true;
                mosse.push({c0, w});
            }
    }

    return false;
}

int pianifica(int N, int M, int P1, int D1, int P2, int D2, int A[], int B[])
{
    ::N = N, ::M = M, ::D[0] = D1, D[1] = D2, ::P[0] = P1, ::P[1] = P2;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            dists[i][j] = INT_MAX;


    for(int i = 0; i < M; i++ ) {
        adj[A[i]].push_back(B[i]);
        adj[B[i]].push_back(A[i]);
    }
    for(int i = 0; i < N; i++)
        bfs(i);


    int lo = 0, hi = min(dists[P1][P2], dists[D1][D2])+1;

    while(hi - lo > 1)
    {
        int m = (lo+hi)/2;
        if(possible(m))
            lo = m;
        else hi = m;
    }
    return lo;
}
