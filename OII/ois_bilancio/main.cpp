#include <cstdio>

using namespace std;

#define MAX 1000000
int cifre[MAX], N, K;
int ris[MAX], l_ris;

int minori[MAX][10];
// minori[i][j] = l'id del primo j compreso in [i, N)

void bilancio()
{
    for(int i = 0; i < 10; i++)
        minori[N-1][i] = N;
    minori[N-1][cifre[N-1]] = N-1;
    for(int i = N-2; i >= 0; i--)
    {
        for(int j = 0; j < 10; j++)
            minori[i][j] = minori[i+1][j];
        minori[i][cifre[i]] = i;
    }

    // compiliamo i minori
    int prec = 0;

    int limit_l = N - K;
    for(int m = 0; m < 10 && l_ris < limit_l; m++)
    {
        int next_min = minori[prec][m];
        if(next_min - prec > K) continue;
        // next_min contiene l'indice del minimo da prendere
        ris[l_ris++] = cifre[next_min];
        K -= (next_min - prec);
        prec = next_min + 1;
        m = -1;
    }
    for(int i = prec; l_ris < limit_l; i++)
        ris[l_ris++] = cifre[i];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++)
        scanf(" %d", &cifre[i]);

    bilancio();

    for(int i = 0; i < l_ris; i++)
        printf( "%d ", ris[i]);
    printf("\n");
}
