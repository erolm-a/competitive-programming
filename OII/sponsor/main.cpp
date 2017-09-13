#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

static int N, M;
static int* nsponsors;
static int** sponsors;

int solve(int, int, int*, int**, int*, int*);

int main(){
    FILE *fin, *fout;
    int i,j;
    assert(fin = fopen("input.txt", "r"));
    assert(fout = fopen("output.txt", "w"));
    assert(2==fscanf(fin, "%d%d", &N, &M));
    nsponsors = (int*) malloc(sizeof(int) * N);
    sponsors = (int**) malloc(sizeof(int*) * N);
    for(i=0; i<N; i++) {
        int Q;
        assert(1==fscanf(fin, "%d", &Q));
        nsponsors[i] = Q;
        sponsors[i] = (int*) malloc(sizeof(int)*Q);
        for(j=0; j<Q; j++)
            assert(1==fscanf(fin, "%d", &sponsors[i][j]));
    }
    int sponsor_a, sponsor_b;
    int res = solve(N, M, nsponsors, sponsors, &sponsor_a, &sponsor_b);
    if(res) fprintf(fout, "1\n");
    else fprintf(fout, "0 %d %d\n", sponsor_a, sponsor_b);
    return 0;
}
