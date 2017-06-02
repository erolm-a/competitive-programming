#include <cstdio>
#include <queue>
#include <limits>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int min_sol = numeric_limits<int>::max();

#define MAX_N 1000
vector<pair<int, int>> grafo[MAX_N];

int N, M;

bool yes(bool i) {return i;}

void dijkstra(int s, int d) {
    int distance [MAX_N];
    fill(distance, distance + N, numeric_limits<int>::max() / 4);
    distance[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> stati;
    int peso;

    for(auto i: grafo[s])
    {
        if(i.second == d)
            peso = i.first;
        else {
            stati.push(i);
            distance[i.second] = i.first;
        }
    }
    while(!stati.empty())
    {
        auto s = stati.top();
        stati.pop();
        if(s.second == d) {
            min_sol = min(min_sol, distance[d] + peso);
            return;
        }
        for(auto j: grafo[s.second])
        {
            int sum = s.first + j.first;
            if(distance[j.second] > sum && sum < min_sol)
            {
                distance[j.second] = sum;
                stati.emplace(distance[j.second], j.second);
            }
        }
    }
}

void risolvi() {
    for(int i = 1; i <= N - 1 ; i++)
        for(auto j: grafo[i])
            if(j.second > i)
                dijkstra(i, j.second);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d %d", &N, &M);

    for(int i = 0; i < M; i++) {
        int a, b, p;
        scanf("%d %d %d", &a, &b, &p);
        grafo[a].emplace_back(p, b);
        grafo[b].emplace_back(p, a);

    }
    risolvi();
    printf("%d\n", min_sol);
}
