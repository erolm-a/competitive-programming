#include <cstdio>
#include <utility>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

#define MAX_N 2000
#define MAX_K 200000

typedef pair<int, int> pii;

int sicurezza[MAX_N][MAX_N];
int dp_sic[MAX_N][MAX_N];
int dp_perc[MAX_N][MAX_N];

namespace soluzione {
    int N, M, K;

    bool test(pii pos) {
        return pos.first >= 0 && pos.first < N && pos.second >= 0 &&
                pos.second < M && sicurezza[pos.second][pos.first] == -1;
    }

    void bfs(int *X, int *Y) {

        queue<pii> coda;
        for(int i = 0; i < K; i++) {
            coda.push(make_pair(X[i], Y[i]));
            sicurezza[Y[i]][X[i]] = 0;
        }

        while(!coda.empty()) {
            pii pos = coda.front();
            coda.pop();
            int x = pos.first, y = pos.second;
            if(test(make_pair(x-1, y))) {
                sicurezza[y][x-1] = sicurezza[y][x] + 1;
                coda.push({x-1, y});
            }
            if(test(make_pair(x+1, y))) {
                sicurezza[y][x + 1] = sicurezza[y][x] + 1;
                coda.push({x+1, y});
            }
            if(test(make_pair(x, y-1))) {
                sicurezza[y-1][x] = sicurezza[y][x] + 1;
                coda.push({x, y-1});
            }
            if(test(make_pair(x, y+1))) {
                sicurezza[y+1][x] = sicurezza[y][x] + 1;
                coda.push({x, y+1});
            }
        }
    }

    void calcola_sicurezza() {
        dp_sic[0][0] = sicurezza[0][0];
        for(int i = 0; i < N; i++)
            dp_sic[0][i] = sicurezza[0][i];
        for(int i = 0; i < M; i++)
            dp_sic[i][0] = sicurezza[i][0];

        for(int i = 1; i < M; i++)
            for(int j = 1; j < N; j++)
                dp_sic[i][j] = min(sicurezza[i][j], max(dp_sic[i-1][j], dp_sic[i][j-1]));
    }

    void calcola_percorsi() {
        dp_perc[0][0] = 1;
        for(int i = 1; i < M; i++)
            if(dp_sic[i][0] >= dp_sic[M-1][N-1])
                dp_perc[i][0] = dp_perc[i-1][0];
            else dp_perc[i][0] = 0;
        for(int j = 1; j < N; j++)
            if(dp_sic[0][j] >= dp_sic[M-1][N-1])
                dp_perc[0][j] = dp_perc[0][j-1];
            else
                dp_perc[0][j] = 0;

        for(int i = 1; i < M; i++)
            for(int j = 1; j < N; j++)
                if(dp_sic[i][j] >= dp_sic[M-1][N-1])
                    dp_perc[i][j] = dp_perc[i-1][j] + dp_perc[i][j-1];
                else
                    dp_perc[i][j] = 0;
    }
}


int ContaPercorsi(int N, int M, int K, int* X, int* Y) {
    soluzione::N = N;
    soluzione::M = M;
    soluzione::K = K;

    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            sicurezza[i][j] = K > 0 ? -1 : INT_MAX ;

    soluzione::bfs(X, Y);
    soluzione::calcola_sicurezza();
    soluzione::calcola_percorsi();


    return dp_perc[M-1][N-1];
}


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);

    int X[N], Y[M];
    for(int i = 0; i < K; i++)
        scanf("%d %d", X + i, Y + i);


    printf("%d\n", ContaPercorsi(N, M, K, X, Y));
    return 0;
}
