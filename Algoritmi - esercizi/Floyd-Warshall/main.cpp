#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

#define MAX 1024
float distanza[MAX][MAX];

int N;

void floyd_warshall() {
    for(int k = 1; k < N; k++)
        for(int i = 1; i < N; i++) {
            if(i == k) // avoid useless cycles
                continue;
            for(int j = 1; j < N; j++) {
                if(j == k) // avoid useless cycles
                    continue;
                if(i != j && distanza[i][j] < distanza[i][k] + distanza[k][j]) // avoid negative cycles
                    disanza[i][j] = distanza[i][k] + distanza[k][j];
            }
        }
}

void stampa() {
    FILE *out = fopen("write.txt", "w");
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            fprintf(out, "%d %d %.0f", i, j, isfinite(distanza[i][j]));
}

int main()
{
    FILE* in = fopen("input.txt", "r");

    for(int i = 0; i < MAX; i++)
        distanza[i] = INFINITY;

    int archi, da, a; float peso;
    fscanf(in, "%d %d", &N, &archi);

    for(int i = 0; i < archi; i++) {
        fscanf(in, " %d %d %f", &da, &a, &peso);
        distanza[da][da] = 0;
        distanza[a][a] = 0;
        distanza[da][a] = peso;
    }
    floyd_warshall();
    stampa();

    return 0;
}
