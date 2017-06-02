#include <stdio.h>
#include <assert.h>

#define MAXN 100000

int kindle(int N, int M, int K, int L[]) {
    int somma = 0, i = 0, cont = 0;

    if(K == M) {
        for(int i = 0; i < N; i++)
            if(L[i] == 0)
                cont++;
        return cont;
    }
    if(M == N) {
        for(int i = 0; i < N; i++)
            if(L[i] == 1)
                cont++;
        if(cont >= K)
            return 0;
        return K - cont;
    }

    for(; i < M; i++)
        somma += L[i];


    for(; i < N; i++) {
        if(somma < K) {
            for(int j = i-1, scarto = K - somma;
                           scarto > 0 && j >= i - K; j--)
                if(L[j] == 0) L[j] = 1, scarto--, cont++;
            somma = K;
        }
        somma -= L[i-M];
        somma += L[i];
    }
    return cont;
}


int L[MAXN];

int main() {
    FILE *fr, *fw;
    int N, M, K, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(3 == fscanf(fr, "%d %d %d", &N, &M, &K));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &L[i]));

    fprintf(fw, "%d\n", kindle(N, M, K, L));
    fclose(fr);
    fclose(fw);
    return 0;
}
