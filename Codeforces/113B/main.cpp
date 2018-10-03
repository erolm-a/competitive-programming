#include <bits/stdc++.h>

using namespace std;


#define MAX_N 3010
char T[MAX_N];
int n;
using ii = pair<int, int>;
int SA[MAX_N], RA[MAX_N], temp_RA[MAX_N], temp_SA[MAX_N];
int c[MAX_N];

void counting_sort(int k) {
    int t = 0, sum = 0, maxi = max(300, n);
    memset(c, 0, sizeof(c));
    for(int i = 0; i < n; i++)
        c[i + k < n ? RA[i+k] : 0 ]++;
    for(int i = 0; i < maxi; i++)
        t = c[i], c[i] = sum, sum += t;
    for(int i = 0; i < n; i++)
        temp_SA[c[SA[i] + k < n ? RA[SA[i]+k] : 0 ]++] = SA[i];
    copy(temp_SA, temp_SA + n, SA);
}

void build_suffarr() {
    int k, r;
    copy(T, T + n, RA);
    iota(SA, SA + n, 0);

    for(k = 1; k < n; k<<=1) {
        counting_sort(k);
        counting_sort(0);
        temp_RA[SA[0]] = r = 0;
        for(int i = 1; i < n; i++)
            temp_RA[SA[i]] = RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1] + k] ?
                        r : ++r;
        copy(temp_RA, temp_RA + n, RA);
        if(RA[SA[n-1]] == n-1) return;
    }
}

ii find_occ(string& occ)
{
    int m = occ.size();
    int lo = 0, hi = n - 1, mid = lo;
    while(lo < hi)
    {
        mid = (lo + hi)/2;
        int res = strncmp(T + SA[mid], occ.c_str(), m);
        if(res >= 0) hi = mid;
        else lo = mid +1;
    }
    if(strncmp(T + SA[lo], occ.c_str(), m)) return {-1, -1};
    ii ans; ans.first = lo;

    lo = 0, hi = n-1;
    while(lo < hi)
    {
        mid = (lo + hi)/2;
        int res = strncmp(T + SA[mid], occ.c_str(), m);
        if(res > 0) hi = mid;
        else lo = mid+1;
    }
    if(strncmp(T + SA[hi], occ.c_str(), m) != 0) hi--;
    ans.second = hi;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> T;
    n = strlen(T);
    T[n++] = '$';

    string s_beg, s_end;
    cin >> s_beg >> s_end;

    build_suffarr();

    ii begs = find_occ(s_beg), ends = find_occ(s_end);
    vector<int> begv, endv;

    if(begs.first == -1 || begs.second == -1 || ends.first == -1 || ends.second == -1) {
        cout << "0\n"; return 0;
    }

    for(int i = begs.first; i <= begs.second; i++)
        begv.push_back(SA[i]);

    for(int i = ends.first; i <= ends.second; i++)
        endv.push_back(SA[i]);

    // stupid O(N^2) approach - today I'm sick and tired of doing the O(NlogN) version

    unordered_set<string> found;
    for(int i: begv)
        for(int j: endv)
            if(i <= j) {
                string str(T + i, j - i + 1);
                cout << "Testo la stringa: " << str << '\n';
                found.insert(string(T + i, j - i + 1));
            }
    cout << found.size() << '\n';

    return 0;
}
