#include <bits/stdc++.h>

using namespace std;
#define MAX_N 100000
int N;
int queries[MAX_N][3];
struct ST {
    bool lazy[4*MAX_N];
    int testa[4*MAX_N];

    void update(int ub, int ue) {_update(ub, ue, 0, N-1, 0);}
    void _update(int ub, int ue, int l, int r, int root)
    {
        if(lazy[root]) {
            lazy[root] = false;
            testa[root] = r - l + 1 - testa[root];
            if(l != r)
                lazy[root*2+1] = !lazy[root*2+1],
                        lazy[root*2+2] = !lazy[root*2+2];
        }
        if(ue < l || ub > r)
            return;
        if(ub <= l && r <= ue)
        {
            testa[root] = r - l + 1 - testa[root];
            if(l != r)
                lazy[root*2+1] = !lazy[root*2+1],
                        lazy[root*2+2] = !lazy[root*2+2];
            return;
        }
        int m = (l+r)/2;
        _update(ub, ue, l, m, root*2+1);
        _update(ub, ue, m+1, r, root*2+2);
        testa[root] = testa[root*2+1] + testa[root*2+2];
    }

    int query(int ub, int ue) {return _query(ub, ue, 0, N-1, 0);}
    int _query(int ub, int ue, int l, int r, int root)
    {
        if(lazy[root]) {
            lazy[root] = false;
            testa[root] = r - l + 1 - testa[root];
            if(l != r)
                lazy[root*2+1] = !lazy[root*2+1],
                        lazy[root*2+2] = !lazy[root*2+2];
        }
        if(ue < l || ub > r)
            return 0;
        if(ub <= l && r <= ue) return testa[root];
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
