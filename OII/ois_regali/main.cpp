#include <cstdio>
#include <algorithm>
#include <array>

#define MAX_Q 100

int N, Q;


using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d %d", &N, &Q);
    array<int, MAX_Q> regali[N];

    for(int i = 0; i < N; i++)
        for(int j = 0; j < Q; j++)
            scanf(" %d", &regali[i][j]);

    sort(regali, regali + N, [](const array<int, MAX_Q> &a,
                                const array<int, MAX_Q> &b) {
             for(int i = 0; i < Q; i++)
                 if(a[i] < b[i]) return true;
                 else if(a[i] > b[i]) return false;
             return true;
         });

    int res = 0;
    for(int i = 1; i < N; i++) {
        int j;
        for(j = 0; j < Q && regali[i-1][j] == regali[i][j]; j++);
        res = max(res, j);
    }

    printf("%d\n", res);
}
