#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

static int N;
static int* vals;

int solve(int, int*);

int main(){
    FILE *fin, *fout;
    int i,j;
    assert(fin = fopen("input.txt", "r"));
    assert(fout = fopen("output.txt", "w"));
    fscanf(fin, "%d", &N);
    vals = (int*) malloc(sizeof(int) * N);
    for(i=0; i<N; i++) fscanf(fin, "%d", &vals[i]);
    fprintf(fout, "%d\n", solve(N, vals));
    return 0;
}
