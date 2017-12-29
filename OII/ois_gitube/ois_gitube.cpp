#include <stdio.h>
#include <assert.h>

#define MAX_N 100000

int mat[MAX_N];

int C[MAX_N];

int main() {
    FILE *fr, *fw;
    int D, N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d %d", &D, &N));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &C[i]));
    
    for(i=0; i<N; i++)
      mat[C[i]-1]++;

    for(i=0; i<7;i++) {
      for(int j=0; i+j*7 < D; j++) {
        if(mat[i+j*7]<10)
          fputc('.', fw);
        else if(mat[i+j*7]<20)
          fputc('o', fw);
        else fputc('O', fw);
 	}
      fprintf(fw, "\n");
    }
    
    fclose(fr);
    fclose(fw);
    return 0;
}
