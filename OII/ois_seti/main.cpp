#include <stdio.h>
#include <assert.h>

#define MAXN 1000000
#define MODULO 1000000007

int receive(int N, int V[]) {
    // insert your code here
    int dp[N];

    dp[0] = 2;
    for(int i = 1; i < N; i++) {
        if(i - V[i] <= 0)
            dp[i] = (dp[i-1] + 1 ) % MODULO;
        else
            dp[i] = (dp[i - V[i] - 1] + dp[i-1]) % MODULO;

    }

    return dp[N-1];
}


int V[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &V[i]));

    fprintf(fw, "%d\n", receive(N, V));
    fclose(fr);
    fclose(fw);
    return 0;
}
