#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

static FILE *fr, *fw;

// Declaring variables
static int P;
static int M;
static int* C;
static int* E;

// Declaring functions
void inizializza(int P, int M);
int controlla(int checksum);

int main() {
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");

    // Iterators used in for loops
    int i0;

    // Reading input
        fscanf(fr, "%d %d", &P, &M);
    C = (int*)malloc(P * sizeof(int));
    for (i0 = 0; i0 < P; i0++) {
            fscanf(fr, "%d", &C[i0]);
    }

    // Calling functions
        inizializza(P, M);

    E = (int*)malloc(P * sizeof(int));

        for (i0 = 0; i0 < P; i0++) {
            E[i0] = controlla(C[i0]);
        }

        // Writing output
    for (i0 = 0; i0 < P; i0++) {
            fprintf(fw, "%d ", E[i0]);
    }
    fprintf(fw, "\n");

    fclose(fr);
    fclose(fw);
    return 0;
}
