#include <bits/stdc++.h>

using namespace std;

#define MAX_N 50001

bool visited[MAX_N];
pair<int, int> grafo[MAX_N];

int find(int start, int end) {
    int next = start, costo = 0;
    for(next = start; next != end && !visited[next]; next = grafo[next].second, costo++)
        visited[next] = true;
    return next == end ? costo : -1;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int M, start, end;
    scanf("%*d %d %d %d", &M, &start, &end);

    for(int i = 0; i < M; i++) {
        int da, a, c;
        scanf("%d %d %d", &da, &a, &c);
        if(grafo[da].first == 0)
            grafo[da] = make_pair(c, a);
        if(grafo[a].first == 0)
            grafo[a] = make_pair(c, da);

        grafo[da] = min(grafo[da], make_pair(c, a)),
                grafo[a] = min(grafo[a], make_pair(c, da));
    }

    printf("%d\n", find(start, end));
    return 0;
}
