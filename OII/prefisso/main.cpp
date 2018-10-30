#include <bits/stdc++.h>

using namespace std;

#define MAX_S 21
#define MAX_N 30000

char str[MAX_N][MAX_S];
int n;

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf(" %s", str[i]);
    int sol;
    for(sol = 0; sol < 20; sol++) {
        char r = str[0][sol];
        for(int j = 1; j < n; j++)
            if(r != str[j][sol])
                goto fine;
    }
    fine:

    printf("%d\n", sol);
}
