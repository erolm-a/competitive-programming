#include <bits/stdc++.h>

#define MAX_N 200000
using ll = long long;
using pll = std::pair<ll, ll>;

int N; ll T;
std::vector<int> adj1[MAX_N], adj2[MAX_N];

ll dists[MAX_N][2];

using namespace std;

ll dijkstra()
{
    priority_queue<pll, vector<pll>, greater<pll>> states;

    fill(*dists, *dists + 2*N, LLONG_MAX);

    states.push(make_pair(0ll, 0ll));
    while(!states.empty()) {
        pll p = states.top();
        states.pop();
        if(p.second == N-1)
            return p.first;
        if(p.first < T)
            for(ll i: adj1[p.second])
                if(dists[i][0] > p.first + 1) {
                    dists[i][0] = p.first + 1;
                    states.push(make_pair(dists[i][0], i));
                }
        for(ll i: adj2[p.second])
            if(dists[i][1] > max(T, p.first)+1) {
                dists[i][1] = max(T, p.first)+1;
                states.push(make_pair(dists[i][1], i));
            }
    }
    return -1;
}

int solve(int N, int M, int T, int* S, int* E)
{
    ::N = N, ::T = T;
    for(int i = 0; i < M; i++) {
        adj1[S[i]].push_back(E[i]);
        adj2[E[i]].push_back(S[i]);
    }

    return (int) dijkstra();
}
