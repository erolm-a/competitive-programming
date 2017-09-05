#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX_S 100000
#define MAX_N 1000000

int lcp(char* a, char* b, int N) {int n = 0; for(; n < N && a[n] == b[n]; n++); return n;}

int RA[MAX_S+2], SA[MAX_S+2], tempRA[MAX_S+2], tempSA[MAX_S+2];
char S[MAX_S+2], N[MAX_N+1];
int c[MAX_S+2], s_len, n_len;

char *X = N;

void countingsort(int k)
{
    int i = 0, sum, maxi = max(s_len, 300), t;
    memset(c, 0, sizeof(c));
    for(i = 0; i < s_len; i++)
        c[i + k < s_len ? RA[i + k] : 0]++;
    for(i = sum = 0; i < maxi; i++)
        t = c[i], c[i] = sum, sum += t;
    for(i = 0; i < s_len; i++)
        tempSA[c[SA[i] + k < s_len ? RA[SA[i] + k] : 0]++] = SA[i];
    copy(tempSA, tempSA + s_len, SA);
}

void build_suffix()
{
    int i, k, r;
    copy(S, S + s_len, RA);
    for(i = 0; i < s_len; i++) SA[i] = i;
    for(k = 1; k < s_len; k<<=1) {
        countingsort(k);
        countingsort(0);
        tempRA[SA[0]] = r = 0;
        for(i = 1; i < s_len; i++) tempRA[SA[i]] =
                (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i] + k] == RA[SA[i-1] + k]) ? r : ++r;
        copy(tempRA, tempRA + s_len, RA);
        if(RA[SA[s_len-1]] == s_len-1) break;
    }
}

int match_string()
{
    int lo = 0, hi = s_len, max_lcp = 0, mid = lo;
    while(lo < hi)
    {
        mid = (lo + hi) / 2;
        int res = lcp(S + SA[mid], X, min(s_len, n_len));
        if(res == min(s_len, n_len))
            return res;
        if(*(S + SA[mid] + res) < X[res]) lo = mid + 1;
        else hi = mid;
        max_lcp = max(max_lcp, res);
    }
    return max(max_lcp, lcp(S + SA[hi], X, min(s_len, n_len)));
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    gets(N); // someone forgive me
    n_len = strlen(N);
    gets(S); // again
    s_len = strlen(S);
    S[s_len++] = '\n';

    build_suffix();
    int op, res;
    for(op = 0; n_len > 0 ; op++) {
        X += (res = match_string());
        n_len -= res;
    }
    printf("%d\n", op);
}
