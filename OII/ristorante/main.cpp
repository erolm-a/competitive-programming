#include <cstdio>
#include <numeric>
#include <algorithm>

using namespace std;

#define MAX_N 100000
int main()
{
    int N, D, M;
    int A[MAX_N];

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d %d", &N, &D);
    for(int i = 0; i < N; i++)
        scanf(" %d", A + i);
    scanf("%d", &M);
    if(M > N)
        printf("%d\n", accumulate(A, A + N, 0) - (M - N) * D);
    else {
        sort(A, A + N);
        printf("%d\n", accumulate(A, A + M, 0));
    }
    return 0;
}
