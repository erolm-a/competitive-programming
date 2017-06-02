#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_P 1000
#define MAX_N 10000
int monete[MAX_P][MAX_N+1]; // in 0, dimensione

int find_minimum(int i)
{
    sort(monete[i]+1, monete[i] + monete[i][0] + 1);
    int X = 0;
    for(int j = 1; j < monete[i][0]; j++) {
        if(monete[i][j] > X + 1)
            return X + 1;
        X += monete[i][j];
    }
    return X+1;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int P;
    scanf("%d", &P);
    for(int i = 0; i < P; i++) {
        scanf("%d", monete[i]);
        for(int j = 1; j <= monete[i][0]; j++)
            scanf("%d", monete[i] + j);
    }
    for(int i = 0; i < P; i++)
        printf("%d\n", find_minimum(i));
}
