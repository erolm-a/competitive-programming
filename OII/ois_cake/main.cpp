#include <cstdio>

int main() {
    long long N;

    scanf("%lld", &N);
    printf("%lld", (N/2 + 1)*(N/2 + 1 + N % 2));
}
