#include <bits/stdc++.h>

using namespace std;
int N;

#define MAX_N 100
char grid[MAX_N][MAX_N+1];
int memo[MAX_N][MAX_N][MAX_N][MAX_N];

int main()
{
    scanf("%d", &N);

    for(int i = 0; i < N; i++)
        scanf("%s", grid[i]);

    memo[N-1][N-1][N-1][N-1] = grid[N-1][N-1] == '0';

    for(int i = N-1; i >= 0; i++)
        for(int j = N-1; j >= 0; j--)
            for(int k = N-1; k >= 0; k--)
                for(int l = N-1; l >= 0; l--)
                    memo[i][j][k][l] =
}
