#include <bits/stdc++.h>

using namespace std;

#define MAX_S 4010

int dp[MAX_S][MAX_S];

char a[MAX_S], b[MAX_S];
int sz_a, sz_b;
int ti, td, tr, te;
int S1[MAX_S][26], S2[MAX_S][26];
int last_row[MAX_S][26], last_col[MAX_S][26];
#define ch(x) (x-'a')

int main()
{
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d %d %d %d", &ti, &td, &tr, &te);
    scanf(" %s %s", a, b);
    sz_a = strlen(a), sz_b = strlen(b);

    for(int i = 0; i <= sz_a; i++)
        dp[0][i] = i*td;
    for(int i = 0; i <= sz_b; i++)
        dp[i][0] = i*ti;

    for(int i = 1; i <= sz_b; i++) {
        memcpy(last_row[i], last_col[i-1], 26*sizeof(int));
        last_col[i][ch(b[i-1])] = i;
    }
    for(int i = 1; i <= sz_a; i++) {
        memcpy(last_col[i], last_col[i-1], 26*sizeof(int));
        last_col[i][ch(a[i-1])] = i;
    }


    for(int i = 1; i <= sz_b; i++)
        for(int j = 1; j <= sz_a; j++) {
            int &r = dp[i][j];
            r = min({dp[i-1][j]+ti,
                            dp[i][j-1]+td,
                            dp[i-1][j-1] + (b[i-1]!=a[j-1])*tr
                           });
            if(i > 1&& j > 1) {
                int lr = last_row[i-1][ch(a[j-1])], lc = last_col[j-1][ch(b[i-1])];
                if(lr&&lc)
                r = min(r, dp[lr-1][lc-1] + (i - lr -1)*ti + (j - lc -1)*td + te);
            }
        }

    printf("%d\n", dp[sz_b][sz_a]);
}
