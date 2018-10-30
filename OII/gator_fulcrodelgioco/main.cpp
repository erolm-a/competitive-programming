#include <bits/stdc++.h>

using namespace std;

#define MAX_N 11
vector<int> graph[MAX_N+1];
bitset<MAX_N+1> visited;
int unvisited;

int unreachable = 0, best_denied_id;
void visit(int root, int denied)
{
    if(visited[root]) return;
    int s = root;
    queue<int> stats;
    stats.push(s);
    visited[root] = true;
    while(!stats.empty()) {
        s = stats.front();
        stats.pop();
        unvisited--;
        for(int i: graph[s]) {
            if(i != denied && !visited[i]) {
                visited[i] = true;
                stats.push(i);
            }
        }
    }
}

int main()
{
    int M;
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d", &M);
    for(int i = 0; i < M; i++)
    {
        int a, b; scanf("%d %d", &a, &b);
        graph[a].push_back(b);
    }

    for(int i = 2; i <= MAX_N; i++) {
        visited.reset();
        unvisited = MAX_N;
        for(int root = 1; root <= MAX_N; root++) {
            if(root == i) continue;
            visit(root, i);
            if(unvisited > unreachable)
                unreachable = unvisited, best_denied_id = i;
        }
    }
    printf("%d", best_denied_id);
}
