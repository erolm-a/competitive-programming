#include <cstring>
#include <cstdio>
#include <algorithm>
#include <utility>

#define MAX_S 100000
using namespace std;

using ii = pair<int, int>;
char T[MAX_S+2];
int n, SA[MAX_S], tempSA[MAX_S], RA[MAX_S], tempRA[MAX_S], c[MAX_S];
char P[MAX_S]; int m;

void counting_sort(int k)
{
    int i, sum, t, maxi = max(300, n);
    memset(c, 0, sizeof c);
    for(i = 0; i < n; i++)
        c[i + k < n ? RA[i+k] : 0]++;
    for(i = sum = 0; i < maxi; i++)
        t = c[i], c[i] = sum, sum+=t;
    for(i = 0; i < n; i++)
        tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
    copy(tempSA, tempSA + n, SA);
}

void build_suffix_array()
{
    int i, k, r;
    copy(T, T + n, RA);
    for(i = 0; i < n; i++) SA[i] = i;
    for(k = 1; k < n; k<<=1) {
        for(int i = 0; i < n; i++) printf("%d\n", RA[i]);
        counting_sort(k);
        counting_sort(0);
        tempRA[SA[0]] = r = 0;
        for(i = 1; i < n; i++)
            tempRA[SA[i]] =
                    (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i] + k] == RA[SA[i-1] + k]) ? r : ++r;
        copy(tempRA, tempRA + n, RA);
        if(RA[SA[n-1]] == n-1) return;
    }
}

// cerchiamo sia lower che upper bound
ii find_occ()
{
    int lo = 0, hi = n-1, mid = lo;
    while(lo < hi) {
        mid = (lo + hi) / 2;
        int res = strncmp(T + SA[mid], P, m);
        if(res >= 0) hi = mid;
        else lo = mid + 1;
    }
    if(strncmp(T + SA[lo], P, m) != 0) return {-1, -1}; // not found
    ii ans; ans.first = lo;
    lo = 0, hi = n-1;
    while(lo < hi) {
        mid = (lo + hi) / 2;
        int res = strncmp(T + SA[mid], P, m);
        if(res > 0) hi = mid;
        else lo = mid + 1;
    }
    if(strncmp(T + SA[lo], P, m) != 0) hi--;
    ans.second = hi;
    return ans;
}

int main()
{
    n = strlen(gets(T));
    T[n++] = '$';
    build_suffix_array();
    for(int i = 0; i < n; i++) printf("%d %s\n", SA[i], T + SA[i]);
    while(m = (int)strlen(gets(P)), m) {
        ii pos = find_occ();
        if(pos.first != -1 && pos.second != -1)
        {
            printf("%s found, SA[%d..%d] of %s\n", P, pos.first, pos.second, T);
            printf("That is: \n");
            for(int i = pos.first; i <= pos.second; i++)
                printf("%s\n", T + SA[i]);
        } else printf("Not found in %s\n", T);
    }
}
