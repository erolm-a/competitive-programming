#include <cstdio>
#include <algorithm>
#include <queue>
#include <limits>

using namespace std;

#define MAX_N 1000
int dist[MAX_N + 1];
int N;
vector<pair<int, int>> adj[MAX_N+1];
void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> states;
    fill(dist + 2, dist + N + 1, numeric_limits<int>::max());
    for(auto i: adj[1]) {
        states.push(i);
        dist[i.second] = i.first;
    }
    while(!states.empty()) {
        auto p = states.top();
        states.pop();
        for(auto i: adj[p.second])
            if(i.first + p.first < dist[i.second]) {
                dist[i.second] = i.first + p.first;
                states.push_back(make_pair(dist[i.second], i.second));
            }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int M;

    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++) {
        int da, a, peso;
        scanf(" %d %d %d", &da, &a, &peso);
        adj[da].push_back(make_pair(peso, a));
        adj[a].push_back(make_pair(peso, da));
    }
    dijkstra();
    int counter = 1;
    for(int i = 2; i <= N; i++)
        if(dist[i] <= 10*i) counter++;
    printf("%d\n", counter);
    return 0;

}
