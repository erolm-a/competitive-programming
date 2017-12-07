#include <bits/stdc++.h>


using namespace std;
#define MAX_N 4000001
int N;
int queries[MAX_N][4];
struct ST {
    long long lazy[4*MAX_N];
    long long tree[4*MAX_N];

    void update(int ub, int ue, long long inc) {_update(ub-1, ue-1, 0, N-1, inc, 0);}
    void _update(int ub, int ue, int l, int r, long long inc, int root)
    {
        if(lazy[root]) {
            tree[root] += (r - l + 1)*lazy[root];
            if(l != r)
                lazy[root*2+1] += lazy[root],
                        lazy[root*2+2] += lazy[root];
            lazy[root] = 0;
        }
        if(ue < l || ub > r)
            return;
        if(ub <= l && r <= ue)
        {
            tree[root] += (r - l + 1)*inc;
            if(l != r)
                lazy[root*2+1] += inc, lazy[root*2+2] += inc;
            return;
        }
        int m = (l+r)/2;
        _update(ub, ue, l, m, inc, root*2+1);
        _update(ub, ue, m+1, r, inc, root*2+2);
        tree[root] = tree[root*2+1] + tree[root*2+2];
    }

    long long query(int ub, int ue) {return _query(ub-1, ue-1, 0, N-1, 0);}
    long long _query(int ub, int ue, int l, int r, int root)
    {
        if(lazy[root]) {
            tree[root] += (r - l + 1)*lazy[root];
            if(l != r)
                lazy[root*2+1] += lazy[root],
                        lazy[root*2+2] += lazy[root];
            lazy[root] = 0;
        }
        if(ue < l || ub > r)
            return 0;
        if(ub <= l && r <= ue) return tree[root];
        int m = (l+r)/2;
        return _query(ub, ue, l, m, root*2+1) + _query(ub, ue, m+1, r, root*2+2);
    }
    void clear() {memset(tree, 0, sizeof(tree)/sizeof(int)); memset(lazy, 0, sizeof(lazy)/sizeof(int));}
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
    int Q;
    int tc = readInt();

    while(tc--) {
        N = readInt(), Q = readInt();
        for(int i = 0; i < Q; i++) {
            queries[i][0] = readInt(),
            queries[i][1] = readInt(),
            queries[i][2] = readInt();
            if(!queries[i][0]) queries[i][3] = readInt();
        }
        for(int i = 0; i < Q; i++)
            switch(queries[i][0])
            {
            case 0:
                nums.update(queries[i][1], queries[i][2], queries[i][3]);
                break;
            case 1:
                printf("%lld\n", nums.query(queries[i][1], queries[i][2]));
                break;
            }
        nums.clear();
    }
}
