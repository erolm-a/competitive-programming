#include <cstdio>

int dis[99999];
int N;

int main()
{
    int inizio, c = 1, d = 1;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &N);
    inizio = N;
    (void)getchar();
    for(int i = 0; i < N-1; i++)
        if((dis[i] = getchar()) == '<')
            inizio--;

    printf("%d ", inizio);
    for(int i = 0; i < N-1; i++)
        printf("%d ", dis[i] == '>' ? (inizio - c++) : (inizio + d++));

    return 0;
}
