#include <bits/stdc++.h>

#define MAXQ 100000

using namespace std;

char T[MAXQ];
int K[MAXQ];
int where[MAXQ]; // dove sta il passeggero con id i
int who[MAXQ]; // chi sta nella sedia i
int N, Q, i;

int experiment() {
    int ris = 0;
    set<int> places;
    for(int i = 0; i < N; i++)
    {
        places.insert(i);
        who[i] = where[i] = -1;
    }
    for(int i = 0; i < Q; i++) {
        if(T[i] == 'l') {
            who[where[K[i]]] = -1;
            places.insert(where[K[i]]);
            where[K[i]] = -1;
        }
        else {
            // cerca il primo posto disponibile
            int pos = min(*places.begin(), K[i]);
            if(who[pos] == -1) {
                who[pos] = K[i];
                where[K[i]] = pos;
            }
            else {
                for(int prec = K[i]; who[pos] != -1; pos = prec, ris++) {
                    swap(who[pos], prec);
                    where[pos] = pos;
                }
                who[pos] = where[pos] = pos;
            }
            places.erase(pos);
        }
    }
    return ris;
}

int main() {
    FILE *fr, *fw;
#ifdef EVAL
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin, fw = stdout;
#endif

    assert(2 == fscanf(fr, "%d%d", &N, &Q));
    for(i=0; i<Q; i++) {
        assert(1 == fscanf(fr, " %c", &T[i]));
        assert(1 == fscanf(fr, " %d", &K[i]));
    }

    fprintf(fw, "%d\n", experiment());
    fclose(fr);
    fclose(fw);
    return 0;
}
