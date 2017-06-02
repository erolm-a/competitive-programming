#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

#define MAX 100000
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T, N, V[MAX];

    int Q[MAX][2];

    scanf("%d %d", &N, &T);
    for(int i = 0; i < N; i++)
        scanf("%d", &V[i]);

    for(int i = 0; i < T; i++)
        scanf("%d %d", &Q[i][0], &Q[i][1]);

    for(int i = 0; i < T; i++) {
        int left = upper_bound(V, V + N, Q[i][0]) - V;
        int right = N - left;

        if(left > right)
            printf("0 ");
        else if(right > left)
            printf("1 ");
        else printf("%d ", Q[i][1]);
    }

    printf("\n");

    return 0;
}
