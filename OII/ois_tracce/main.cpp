#include <cstdio>

#define MAX_K 1000000
#define MODULO 1000000007
long long con[MAX_K+1], con_sum[MAX_K+1], pot10[MAX_K+1];
char s[MAX_K/10];
int K, S;

long long conta() {
    pot10[0] = 1;
    con_sum[S] = con[S] = 1;
    for(int i = S+1; i <= K; i++) {
        pot10[i-S] = (pot10[i-S-1]*10) % MODULO;
        con_sum[i-S] = (10*con_sum[i-S-1] + con[i-S]) % MODULO;
        con[i] = (MODULO + (((i-S+1)*pot10[i-S]) % MODULO) - con_sum[i-S]) % MODULO;
    }
    return con[K];
}
using namespace std;

int main()
{
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    scanf("%d", &K);
    scanf(" %*s%n", &S);
    S--;
    printf("%lld\n", conta());
}
