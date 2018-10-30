#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1000001
using pll = pair<long long, long long>;
vector<pll> adj[MAX_N];
long long dist[MAX_N];
int N;
long long dijkstra()
{
    priority_queue<pll, vector<pll>, greater<pll>> stati;
    stati.push({0ll, 1ll});
    fill(dist+1, dist + N+1, LLONG_MAX/4);
    dist[1] = 0;

    while(!stati.empty()) {
        int i = stati.top().second;
        stati.pop();
        if(i == N) return dist[N];
        for(pll u: adj[i])
            if(dist[u.second] > dist[i] + u.first)
                stati.push({(dist[u.second] = dist[i]+u.first), u.second});
    }
    return -1;
}
int main()
{
    int M;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        adj[a].push_back({c,b});
        adj[b].push_back({c,a});
    }
    printf("%lld\n", dijkstra());
}
