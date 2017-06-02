#include <cstdio>
#include <algorithm>
#include <stack>
#include <utility>

using namespace std;

#define M 1000000007

#define MAX_N 10000

int newton[MAX_N+1][MAX_N+1];

int potenza(int exp) {
    long long base = 1;
    while(exp-- > 0)
        base = ((base%M) *10) % M;

    return (int) base;
}


void preprocess() {
    fill(newton[0], newton[0] + MAX_N, 1);
    fill(newton[1], newton[1] + MAX_N, 1);
    for(int i = 1; i < MAX_N; i++) {
        newton[i][0] = 1;
        for(int j = 1; j < i; j++)
            newton[i][j] = newton[i-1][j] + newton[i-1][j-1];
    }
}

void binomio(int n, int k) {
    stack<pair<int, int>> ric;
    while(1) {
        if(n <= MAX_N && k <= MAX_N)
            return newton[k][n];
    }
}

int calcola() {
    long long ris = 0;
    ris = N - K + 1;
    for(int i = 0; i < N - K; i++)
        ris = (ris * 10) % M;
    if(N/K > 1) {
        ris = (ris + M - (N/K - 1)) % M;
        if(N % K > 0) {
            long long shift = N % K + 1;
            for(int i = 0; i < N % K; i++)
                shift = (shift * 10) % M;
            ris = (ris + M - shift) % M;
        }
    }
    return ris;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d %d", &N, &K);

    for(int i = 0; i < 100; i++)
        fprintf(stderr, "%d\n", potenza(i));
    printf("%d\n", calcola());

    return 0;
}
