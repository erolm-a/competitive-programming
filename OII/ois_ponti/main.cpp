#include <cstdlib>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;
#define MAXN 10000
vector<int> adj[MAXN];
int N, M, comps[MAXN];

void dfs(int i, int v) {
    if(comps[v] == -1) {
        comps[v] = i;
        for(auto j: adj[v])
            dfs(i, j);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d %d", &N, &M);
    memset(comps, -1, sizeof comps);
    while(M--) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int counter = 0;
    for(int v = 0; v < N; v++)
        if(comps[v] == -1)
            dfs(counter++, v);

    printf("%d", counter-1);

    return 0;
}
