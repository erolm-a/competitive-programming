#include <cstdio>
#include <cassert>

using namespace std;

void Analizza(int N, int M, int A[], int B[], int T[]);

#define MAX_N 100000

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N, M;
    int *A = new int[MAX_N];
    int *B = new int[MAX_N];
    int T[3] = {0, 0, 0};

    assert(scanf("%d %d", &N, &M) == 2);
    for(int i = 0; i < M; i++)
        scanf("%d %d", A + i, B + i);

    Analizza(N, M, A, B, T);
    printf("%d %d %d\n", T[0], T[1], T[2]);
    return 0;
}

