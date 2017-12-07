#include <bits/stdc++.h>

using namespace std;
#define MAX_N 100000
int N;
int queries[MAX_N][3];
#define mod1(i) moduli[i][0]
#define mod2(i) moduli[i][1]

struct ST {
    int lazy[4*MAX_N];
    int moduli[4*MAX_N][2];

    void update(int ub, int ue) {_update(ub, ue, 0, N-1, 0);}
    void _update(int ub, int ue, int l, int r, int root)
    {
        if(lazy[root] %= 3) {

            int t1 = mod1(root), t2(root);
            int orig = lazy[root];
            for(;lazy[root]; lazy[root]--)
            {
                t1 = r-l+1-mod1(root)-mod2(root);
                t2 = mod1(root);
                mod1(root) = t1;
                mod2(root) = t2;
            }

            if(r != l)
                lazy[root*2+1]+=orig, lazy[root*2+2]+=orig;
        }
        if(ue < l || ub > r)
            return;
        if(ub <= l && r <= ue) {
            int t1 = r-l+1-mod1(root)-mod2(root);
            int t2 = mod1(root);
            mod1(root) = t1;
            mod2(root) = t2;

            if(r != l)
                lazy[root*2+1]++, lazy[root*2+2]++;
            return;
        }
        int m = (l+r)/2;
        _update(ub, ue, l, m, root*2+1);
        _update(ub, ue, m+1, r, root*2+2);
        mod1(root) = mod1(root*2+1) + mod1(root*2+2);
        mod2(root) = mod2(root*2+1) + mod2(root*2+2);
    }

    int query(int ub, int ue) {return _query(ub, ue, 0, N-1, 0);}
    int _query(int ub, int ue, int l, int r, int root)
    {
        if(lazy[root] %= 3) {

            int t1 = mod1(root), t2(root);
            int orig = lazy[root];
            while(lazy[root] > 0)
            {
                t1 = r-l+1-mod1(root)-mod2(root);
                t2 = mod1(root);
                lazy[root]--;
                mod1(root) = t1;
                mod2(root) = t2;
            }

            if(r != l)
                lazy[root*2+1]+=orig, lazy[root*2+2]+=orig;
        }
        if(ue < l || ub > r)
            return 0;
        if(ub <= l && r <= ue) return r-l+1-mod1(root)-mod2(root);
        int m = (l+r)/2;
        return _query(ub, ue, l, m, root*2+1) + _query(ub, ue, m+1, r, root*2+2);
    }
} nums;

int readInt () {
    bool minus = false;
    int result = 0;
    char ch;
    ch = getchar_unlocked();
    while (true) {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar_unlocked();
    }
    if (ch == '-') minus = true; else result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int Q;
    N = readInt(), Q = readInt();
    for(int i = 0; i < Q; i++)
        queries[i][0] = readInt(),
        queries[i][1] = readInt(),
        queries[i][2] = readInt();

    for(int i = 0; i < Q; i++)
        switch(queries[i][0])
        {
        case 0:
            nums.update(queries[i][1], queries[i][2]);
            break;
        case 1:
            printf("%d\n", nums.query(queries[i][1], queries[i][2]));
            break;
        }
}
