#include <stdio.h>

int main()
{
    int N, max = -1;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        int a, b, c;
        scanf("%d %d", &a, &b);
        c = a + b;
        if(c % 2 == 0 && c > max) max = c;
    }
    printf("%d\n", max);
    return 0;
}
