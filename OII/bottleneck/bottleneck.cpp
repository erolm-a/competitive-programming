#include <algorithm>
#include <queue>
#include <vector>
#include <utility>
#include <numeric>
#include <cstdio>

using namespace std;

#define MAX_N 100000
using pii=pair<int, int>;

vector<pii> adj[MAX_N+1];

int W, L, R, C, N;
int vel[MAX_N + 1], dist[MAX_N + 1];

void BFS() {
    queue<int> stati;
    stati.push(W);
    while(!stati.empty())
    {
        int s = stati.front();
        stati.pop();
        if(s == L) break;
        for(pii& v : adj[s])
            if(dist[s] < dist[L] || v.first == L)
            {
                int m = min(vel[s], v.second);
                if(dist[v.first] >= dist[s] + 1)
                    vel[v.first] = min(m, vel[v.first]);
                if(dist[v.first] > dist[s] + 1)
                {
                    dist[v.first] = dist[s] + 1;
                    stati.push(v.first);
                }
            }
//            if((dist[s] < dist[L] || v.first == L) && dist[v.first] > dist[s])
//            {
//                dist[v.first] = dist[s] + 1;
//                vel[v.first] = min(v.second, min(vel[s], vel[v.first]));
//                stati.push(v.first);
//            }

//        for(pii& v : adj[s])
//        {
//            int m = min(vel[s], v.second);

//            if(vel[v.first] > m)
//                vel[v.first] = m;

//            if(dist[v.first] > dist[s] + 1)
//            {
//                dist[v.first] = dist[s] + 1;
//                stati.push(v.first);
//            }
//        }
    }

}

int xl, yl;
inline int distance(int a) {
    int x1 = (a - 1) % C, y1 = (a - 1) / C;
    return abs(x1 - xl) + abs(y1 - yl);
}

void Astar() {
    queue<int> states;
    states.emplace(W);
    const int k = distance(W);

    while(!states.empty())
    {
        int s = states.front();
        states.pop();
        for(pii& v: adj[s])
        {
            if(dist[s] + distance(v.first) == k - 1)
            {
                dist[v.first] = dist[s] + 1;
                int m = min(vel[s], v.second);
                if(vel[v.first] > m)
                {
                    vel[v.first] = m;
                    states.push(v.first);
                }
            }
        }
    }
}

int Analizza(int N, int M, int W, int L, int arco_da[], int arco_a[], int capacita[], int R, int C)
{
    for(int i = 0; i < M; i++) {
        adj[arco_da[i]].push_back({arco_a[i], capacita[i]});
        adj[arco_a[i]].push_back({arco_da[i], capacita[i]});
    }
    ::W = W, ::L = L, ::R = R, ::C = C, ::N = N;
    xl = (L - 1) % C, yl = (L - 1) / C;

    fill(vel + 1, vel + N+1, numeric_limits<int>::max());
    fill(dist + 1, dist + N+1, numeric_limits<int>::max());
    dist[W] = 0;
    if(R == -1)
        BFS();
    else Astar();
    return vel[L];
}
