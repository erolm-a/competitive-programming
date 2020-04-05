#include <stdio.h>

#define MAX_N 100000000
int prefix[MAX_N], suffix[MAX_N], parity[MAX_N], nums[MAX_N];
int found[MAX_N], found_n;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int N;
    scanf("%d", &N);
    for(int i=0; i < N; i++) {
        scanf(" %d", nums + i);
        parity[i] = nums[i] % 2 ? -1 : 1;
    }

    for(int i = 0; i < N-1; ++i)
        prefix[i+1] = prefix[i] + parity[i];
    for(int i = N-1; i > 0; --i)
        suffix[i-1] = suffix[i] + parity[i];

    //for(int i = 0; i < N ; i++)
    //    fprintf(stderr, "%d ", suffix[i]);
    //fprintf(stderr, "\n");

    for(int i = 0; i < N; i++)
        if(prefix[i] == suffix[i] && prefix[i] == 0)
            found[found_n++] = nums[i];

    printf("%d\n", found_n);

    for(int i = 0; i < found_n; i++)
        printf("%d ", found[i]);
    return 0;
}
