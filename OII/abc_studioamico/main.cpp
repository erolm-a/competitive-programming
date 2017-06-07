#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
static FILE *fr, *fw;

// Declaring variables
static int N;
static int* voti2;
static int* voti5;
static int res;

// Declaring functions
bool associabili(int N, int* voti2, int* voti5);

int main() {
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");

    // Iterators used in for loops
    int i0;

    // Reading input
        fscanf(fr, "%d", &N);
    voti2 = (int*)malloc(N * sizeof(int));
    voti5 = (int*)malloc(N * sizeof(int));
    for (i0 = 0; i0 < N; i0++) {
            fscanf(fr, "%d", &voti2[i0]);
    }
    for (i0 = 0; i0 < N; i0++) {
            fscanf(fr, "%d", &voti5[i0]);
    }

    // Calling functions
    res = associabili(N, voti2, voti5);

    // Writing output
        fprintf(fw, "%d\n", res);

    fclose(fr);
    fclose(fw);
    return 0;
}
