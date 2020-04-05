#include <bits/stdc++.h>

using namespace std;

#define MAX_N 101
vector<pair<int, int> > adiacence[MAX_N];

int sol(int N, int A, int B)
{
    vector<int> dist(N+1, INT_MAX/4);
    deque<int> q;

    q.push_back(1);
    dist[1] = 0;

    while(!q.empty())
    {
        int u = q.front();
        q.pop_front();
        if(u == N) return dist[N]; // Dijkstra-like

        for(auto &vertex: adiacence[u])
        {
            int v = vertex.first;
            int w = vertex.second;

            if (dist[v] > dist[u] + w) {
              dist[v] = dist[u] + w;
              if(w) q.push_back(v);
              else q.push_front(v);
            }
        }
    }
    return dist[N];
}

int main()
{
    int N, A, B;
    ifstream inf("input.txt");
    ofstream of("output.txt");
    inf >> N >> A >> B;

    for(int i = 1;i <= A+B;i++)
    {
        int a, b;
        inf >> a >> b;
        adiacence[a].push_back({b, i>A});
        adiacence[b].push_back({a, i>A});
    }

    of << sol(N, A, B) << '\n';
}
