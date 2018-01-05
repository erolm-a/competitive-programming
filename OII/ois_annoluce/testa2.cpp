#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <algorithm>
#define MAXN 100000
long long int XYZ[MAXN];
int A;
void mappatura(int N, int X[], int Y[], int Z[]) {
   for(int i=0;i<N;i++) XYZ[i]=(long long)X[i]*X[i] +(long long)Y[i]*Y[i] + (long long)Z[i]*Z[i];
   A=N;
  std::sort(XYZ,XYZ+A);
}

int query(int D) {
   return std::upper_bound(XYZ,XYZ+A,(long long) D*D)-XYZ;
}


int X[MAXN], Y[MAXN], Z[MAXN];

int main() {
    FILE *fr, *fw;
    int N, Q, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(3 == fscanf(fr, "%d%d%d", &X[i], &Y[i], &Z[i]));

    mappatura(N, X, Y, Z);

    assert(1 == fscanf(fr, "%d", &Q));
    for(i=0; i<Q; i++) {
        int D;
        assert(1 == fscanf(fr, "%d", &D));
        fprintf(fw, "%d\n", query(D));
    }

    fclose(fr);
    fclose(fw);
    return 0;
}
