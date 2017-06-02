#include <stdio.h>
#include <assert.h>
#define MAXN 20000000

static int N, K, i;
static int s[MAXN];

int solve(int N, int K, int* S);

static FILE *fin, *fout;

int main(){
    fin = fopen("input.txt", "r");
    fout = fopen("output.txt", "w");
    assert(2 == fscanf(fin, "%d%d", &N, &K));
    for(i=0; i<N; i++) assert(1 == fscanf(fin, "%d", &s[i]));
    fprintf(fout, "%d\n", solve(N, K, s));
    fclose(fin);
    fclose(fout);
    return 0;
}


#include <cstdio>
#include <algorithm>

#define MAX 20000000
using namespace std;

int *toll;

int frutta(int inizio, int fine, int K) {
    if(inizio >= fine)
        return 0;
    if(K <= 0 && (toll[inizio] != 0 || toll[fine-1] != 0))
        return 0;
    if(toll[inizio] == 0)
        return 1 + frutta(inizio + 1, fine, K);
    if(toll[fine-1] == 0)
            return 1 + frutta(inizio, fine - 1, K);

    return max(frutta(inizio+1, fine, K - toll[inizio]),
                    frutta(inizio, fine-1, K - toll[fine-1]));

}

int solve(int N, int K, int *S) {
    toll = S;
    return frutta(0, N, K);
}
