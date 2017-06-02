#include <bits/stdc++.h>

using namespace std;

#define MAX_V 100000

using pii = pair<int, int>;
vector<pii> grafo[MAX_V+1];
int dist[MAX_V+1];

int N;

int bfs(int u)
{
    fill(dist, dist + N + 1, 0);
    int max_i = u;
    queue<int> coda;
    coda.push(u);
    while(!coda.empty())
    {
        int s = coda.front(); coda.pop();
        for(pii i: grafo[s])
            if(dist[i.first] == 0 && i.first != u) {
                dist[i.first] = dist[s] + i.second;
                if(dist[max_i] < dist[i.first])
                    max_i = i.first;
                coda.push(i.first);
            }
    }
    return max_i;
}

int main()
{
    ios_base::sync_with_stdio(false);
    ifstream i_f("input.txt");
    i_f.tie(0);
    ofstream o_f("output.txt");

    i_f >> N;
    int a, b, c;
    for(int i = 0; i < N; i++)
    {
        i_f >> a >> b >> c;
        grafo[a].push_back(make_pair(b, c));
        grafo[b].push_back(make_pair(a, c));
    }
    int u = bfs(1);
    bfs(u);
    o_f << dist[u] << '\n';
    return 0;
}
