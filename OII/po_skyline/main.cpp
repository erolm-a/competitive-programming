#include <stdio.h>
#include <assert.h>
#define MAXN 1000000

static int H[MAXN];
static int N,subtask,i,K;

int valuta(int N, int* H);
void progetta(int N, int K, int* H);

int main(){
  FILE *in, *out;
  assert(in = fopen("input.txt", "r"));
  assert(out = fopen("output.txt", "w"));

  assert(1==fscanf(in, "%d", &subtask));
  assert(1==fscanf(in, "%d", &N));
  if(subtask == 0){
    for( i = 0 ; i < N ; i++ ) assert( 1 == fscanf(in, "%d", H+i) );
    fprintf(out, "%d\n", valuta(N, H));
  }else if(subtask == 1){
    assert(1==fscanf(in, "%d", &K));
    progetta(N, K, H);
    for( i = 0 ; i < N ; i++ ) {
      if (i) fprintf(out, " ");
      fprintf(out, "%d", H[i]);
    }
    fprintf(out, "\n");
  }
  return 0;
}
