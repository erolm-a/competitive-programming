#include <bits/stdc++.h>

typedef enum {
    OK,
    RISOLTO,
    IMPOSSIBILE
} stato_t;

typedef struct {
    int domino1;
    int domino2;
} coppia_t;

// approccio N^3

static int* altezze, N;

bool cadono()
{
    int l = 0;
    int i = 0;
    for(i = 0; i <= l; i++)
        l = std::min(N-1, std::max(l, i + altezze[i] - 1));
    if(i == N)
        return true;
    return false;
}

stato_t correggi(int N, int altezze[], coppia_t* scambio) {
    // prima di tutto verifichiamo se funziona
    ::altezze = altezze, ::N = N;
    if(cadono())
        return OK;

    for(int i = 0; i < N-1; i++)
        for(int j = i+1; j < N; j++) {
            std::swap(altezze[i], altezze[j]);
            if(cadono())
                return scambio->domino1 = i, scambio->domino2 = j, RISOLTO;
            std::swap(altezze[i], altezze[j]);
        }
    return IMPOSSIBILE;
}
