#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

FILE *fin, *fout;
static int N, K, Q, S, life_left, count_attack;
static int *ans, *calls;

void init(int, int);
int new_pokemon();

bool attack(int P) {
    if (P < 0 || P >= N || life_left == 0) {
        fprintf(fout, "Illecit call to function attack\n");
        exit(0);
    }

    ++count_attack;
    if(count_attack > N) {
        fprintf(fout, "Function attack called too many times\n");
        exit(0);
    }
    if (P < S) return true;
    --life_left;
    return false;
}

int main() {
    fin = fopen("input.txt", "r");
    fout = fopen("output.txt", "w");

    assert(fscanf(fin, "%d%d%d", &N, &K, &Q) == 3);
    ans = (int *)malloc(Q * sizeof(int));
    calls = (int *)malloc(Q * sizeof(int));

    init(N, K);

    for (int i = 0; i < Q; i++) {
        assert(fscanf(fin, "%d", &S) == 1);
        life_left = K;
        count_attack = 0;
        ans[i] = new_pokemon();
        calls[i] = count_attack;
    }

    for (int i = 0; i < Q; i++)
        fprintf(fout, "%d %d\n", ans[i], calls[i]);

    fclose(fin);
    fclose(fout);

    return EXIT_SUCCESS;
}
