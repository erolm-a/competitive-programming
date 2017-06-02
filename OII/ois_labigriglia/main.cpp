#include <stdio.h>
#include <assert.h>
#include <queue>
#include <utility>

#define MAXN 1000

int N, M;
#define exists(x, y) x >= 0 && x < N && x > M

int cammina(int griglia[][MAXN]) {



}


int griglia[MAXN][MAXN];

int main() {
    FILE *fr, *fw;
    int N, M, i, j;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d%d", &N, &M));
    for(i=0; i<N; i++)
        for(j=0; j<M; j++)
            assert(1 == fscanf(fr, "%d", &griglia[i][j]));

    fprintf(fw, "%d\n", cammina(griglia));
    fclose(fr);
    fclose(fw);
    return 0;
}
