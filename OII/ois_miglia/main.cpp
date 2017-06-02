#include <cstdio>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

#define MAX_N 1000


struct Direzione {
    int a, peso;
};

vector<vector<Direzione>> adj;
int N, K, M, D[MAX_N][2];

int risolvi() {
    D[0][0] = 0;

    for(int i = 1; i < N; i++)
        D[i][0] = -1;
    for(int j = 1; j <= K; j++) {
        for(int i = 0; i < N; i++)
            D[i][j%2] = -1;
        for(int i = 0; i < N; i++)
            if(D[i][1-j%2] >= 0)
                for(Direzione x: adj[i])
                    D[x.a][j%2] = max(D[x.a][j%2], D[i][1 - j%2] + x.peso);
    }
    return D[0][K%2];
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d %d %d", &K, &N, &M);

    adj.resize(N);
    for(int i = 0; i < M; i++) {
        int da, a, peso;
        scanf("%d %d %d", &da, &a, &peso);
        adj[da].push_back({a, peso});
    }

    printf("%d\n", risolvi());

    return 0;
}
