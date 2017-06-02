#include <cstdio>
#include <list>

using namespace std;

#define MAX_N 10000

int monete[MAX_N];
bool visitato[MAX_N];
list<int> adj[MAX_N];

int dfs(int moneta);

int main()
{    
    int N, M;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d %d", &N, &M);

    for(int i = 0; i < N; i++)
        scanf(" %d", &monete[i]);



    for(int i = 0; i < M; i++) {
        int a, b;
        scanf(" %d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    printf("%d\n", dfs(0));
}

int dfs(int moneta) {
    visitato[moneta] = true;

    int sum = monete[moneta];
    for(int i: adj[moneta]) {
        if(!visitato[i])
            sum += dfs(i);
    }
    return sum;
}
