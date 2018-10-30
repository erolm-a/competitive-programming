#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_N 500
int A[MAX_N];

int int_rem(int a, int b) {
  return a - floor((float) a/b)*b;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    int N, K;
    scanf("%d%d", &N, &K);
    for(int i = 0; i < N; i++)
      scanf("%d", A+i);

    int V[N]; // stack-allocated... besides N is just <= 500
    for(int p = __builtin_ctz(K); K > 0; K -= (1 << p) , p = __builtin_ctz(K)) {
        for(int i = 0; i < N; i++)
            V[i] = A[i] ^ A[int_rem(i - (1<<p), N)] ^ A[int_rem(i+(1<<p), N)];
        memcpy(A, V, sizeof(int) * N);
    }
    for(int i = 0; i < N; i++)
      printf("%d%c", A[i], " \n"[i==N-1]);
  }
}
