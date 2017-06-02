#include <cstdio>
#include <cassert>
#include <algorithm>

#define MAXQ 100000

using namespace std;
int experiment(int N, int Q, char T[], int K[]) {
    int occupati[N];
    int ris = 0;

    fill(occupati, occupati + N, -1);
    for(int q = 0; q < Q; q++) {
        if(T[q] == 'b') {
            int libero = find(occupati, occupati + N, -1) - occupati;
            if(libero <= K[q])
                occupati[libero] = K[q];
            else {
                int s = K[q], p = occupati[K[q]];

                do {
                    occupati[s] = s;
                    s = p;
                    p = occupati[p];
                    ris++;
                }while(p != -1);
            }
        }
        else
            occupati[K[q]] = -1;
    }

    return ris;
}

char T[MAXQ];
int K[MAXQ];

int main() {
    FILE *fr, *fw;
    int N, Q, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d%d", &N, &Q));
    for(i=0; i<Q; i++) {
        assert(1 == fscanf(fr, " %c", &T[i]));
        assert(1 == fscanf(fr, " %d", &K[i]));
    }

    fprintf(fw, "%d\n", experiment(N, Q, T, K));
    fclose(fr);
    fclose(fw);
    return 0;
}
