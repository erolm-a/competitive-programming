#include <bits/stdc++.h>

using namespace std;

#define MAX 100000
int trampolini[MAX+1], dist[MAX+1];
int N;

int risolvi(){
    dist[0] = 0;
    fill(dist +1, dist + N + 1, INT_MAX/4);

    // per ogni elemento u dell'ordinamento
    for(int u = 0; u < N; u++) {
        // per ogni adiacenza
        for(int v = u + 1; v <= u + trampolini[u]; v++) {
            if(dist[v] < INT_MAX/4) continue;
            if(dist[v] > dist[u] + 1)
                dist[v] = dist[u] + 1;
            if(dist[N] < INT_MAX/4) return dist[N];
        }
    }
    return dist[N];
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf(" %d", &trampolini[i]);
        if(trampolini[i] > N - i)
            trampolini[i] = N - i;
    }
    printf("%d\n", risolvi());
}
