#include <bits/stdc++.h>

using namespace std;
vector<vector<pair<int, int>>> graph;
#define MAX_V 51
bitset<MAX_V> colors;
long long dist[MAX_V];

int N, E;
int sols = 0;
long long mins = LLONG_MAX;

long long dijkstra(int source) {
    auto op = greater<pair<long long, int>>();
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, typeof(op)> q(op);

    bool starting = colors[source];

    fill(dist, dist + N + 1, LLONG_MAX/4);
    q.push({0, source});

    dist[source] = 0;


    while(!q.empty()) {
        auto u = q.top();
        q.pop();
        if(colors[u.second] ^ starting)
            return u.first;
        for(auto v: graph[u.second])
            if(dist[v.second] > u.first + v.first) {
                dist[v.second] = u.first + v.first;
                q.push({dist[v.second], v.second});
            }
    }
    return INT_MAX;
}

void solve(unsigned idx = 1)
{
    if(idx == 1)
        colors.reset();


    if(idx >= N+1) {
        long long s = 0;
        for(int i = 1; i <= N; i++) {
            s += dijkstra(i);
            if(s > mins)
                break;
        }
        if(s < mins) mins = s, sols = 1;
        else if(s == mins) sols++;
    }
    else {
        colors[idx] = true;
        solve(idx+1);
        colors[idx] = false;
        solve(idx+1);
    }
}
int main()
{
    int tc;
    scanf("%d", &tc);

    for(int t = 1; t <= tc; t++) {
        graph.clear();
        sols = 0, mins = LLONG_MAX;
        scanf("%d %d", &N, &E);
        graph.resize(N+1);
        for(int i = 0; i < E; i++) {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            graph[a].push_back({c, b});
            graph[b].push_back({c, a});
        }
        solve();
        printf("Case #%d: %d\n", t, sols);
    }
}
