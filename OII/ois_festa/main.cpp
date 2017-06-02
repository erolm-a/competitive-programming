#include <bits/stdc++.h>

using namespace std;

#define MAX_N 10000
#define MAX_M 100000
bool visitati[MAX_N];
bool imposs[MAX_N];

vector<int> grafo[MAX_N];

int N;
bool DFS(int n) {
    if(imposs[n])
        return false;
    if(visitati[n])
        return true;
    visitati[n] = true;
    int cont = 0;
    for(int i: grafo[n])
        if(DFS(i))
            cont++;
    if(cont < 2)
        return imposs[n] = true, false;
    return true;
}

int risolvi() {
    int sol = 0;
    for(int i = 0; i < N; i++)
        if(DFS(i)) sol++;
    return sol;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int M;
    scanf("%d %d", &N, &M);
    while(M--) {
        int a, b;
        scanf("%d %d", &a, &b);
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }
    printf("%d\n", risolvi());

    return 0;
}
