#include <cstdio>
#include <cmath>

using ll = long long;
#define MAX_N 100000

#define sx(i) i*2
#define dx(i) i*2+1
ll buf[MAX_N];

namespace ST {
    struct lazy_node{
        ll val; bool set;
    };
    struct node {
        ll n, sqn;
        node operator+(const node& o) {return {n+o.n, sqn+o.sqn};}
    };

    node tree[4*MAX_N+1];
    lazy_node lazy[4*MAX_N+1];

    void manage_lazy(int start, int end, int root)
    {
        const int& val = lazy[root].val;
        if(val) {
            int k = (end-start+1);
            if(lazy[root].set) {
                tree[root].n = k*val;
                tree[root].sqn = k*val*val;
                if(k > 1)
                    // brutally erase the children
                    lazy[dx(root)] = lazy[sx(root)] = lazy[root];
            }
            else {
                tree[root].sqn += k*val+2*val*tree[root].n;
                tree[root].n += k*val;
                if(k>1) {
                    // keep sure it won't erase the children unless there was nothing pending
                    if(!lazy[dx(root)].val)
                        lazy[dx(root)].set = false;
                    lazy[dx(root)].val += val;
                    if(!lazy[sx(root)].val)
                        lazy[sx(root)].set = false;
                    lazy[sx(root)].val += val;
                }
            }
            lazy[root] = {0, false};
        }
    }

    node build(int start, int end, int root=1) {
        lazy[root] = lazy_node();
        if(end - start == 0)
            return {tree[root].n = buf[start],
                        tree[root].sqn = buf[start]*buf[start]};
        else {
            int m = (start+end)/2;
            return tree[root] =
                    build(start, m, sx(root)) +
                    build(m+1, end, dx(root));
        }
    }

    node query(int start, int end, int l, int r, int root=1) {
        manage_lazy(l, r, root);
        if(start <= l && r <= end) return tree[root];
        if(start > r || end < l) return {};
        int m = (l+r)/2;
        return query(start, end, l, m, sx(root))+query(start, end, m+1, r, dx(root));
    }

    void incr(int start, int end, int l, int r, int val, int root=1) {
        manage_lazy(l, r, root);
        int k = r-l+1;
        if(start > r || end < l) return;
        if(start <= l && r <= end) {
            tree[root].sqn += k*val*val+2*val*tree[root].n;
            tree[root].n += k*val;
            if(k>1) {
                if(!lazy[dx(root)].val)
                    lazy[dx(root)].set = false;
                lazy[dx(root)].val += val;
                if(!lazy[sx(root)].val)
                    lazy[sx(root)].set = false;
                lazy[sx(root)].val += val;
            }
        }
        else {
            int m = (l+r)/2;
            incr(start, end, l, m, val, sx(root));
            incr(start, end, m+1, r, val, dx(root));
            tree[root] = tree[sx(root)] + tree[dx(root)];
        }
    }

    void set(int start, int end, int l, int r, int val, int root=1) {
        manage_lazy(l, r, root);
        int k = r-l+1;
        if(start > r || end < l) return;
        if(start <= l && r <= end) {
            tree[root].n = k*val;
            tree[root].sqn = k*val*val;
            if(k > 1)
                lazy[dx(root)] = lazy[sx(root)] = {val, true};
        }
        else {
            int m = (l+r)/2;
            set(start, end, l, m, val, sx(root));
            set(start, end, m+1, r, val, dx(root));
            tree[root] = tree[sx(root)] + tree[dx(root)];
        }
    }
}

int main()
{
    int tc, N, Q;

    //freopen("input.txt", "r", stdin);
    scanf("%d", &tc);
    for(int t = 1; t <= tc; t++) {
        printf("Case %d:\n", t);
        scanf("%d %d", &N, &Q);
        for(int i = 0; i < N; i++)
            scanf("%lld", buf+i);

        ST::build(0, N-1);

        while(Q--) {
            int q, a, b, c;
            scanf("%d %d %d", &q, &a, &b);
            switch (q) {
            case 2:
                printf("%lld\n", ST::query(a, b, 1, N).sqn);
                break;
            case 1:
                scanf("%d", &c);
                ST::incr(a, b, 1, N, c);
                break;
            default:
                scanf("%d", &c);
                ST::set(a, b, 1, N, c);
                break;
            }
        }
    }
}
