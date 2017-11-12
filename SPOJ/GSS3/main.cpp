#include <bits/stdc++.h>

#define sx(root) root<<1
#define dx(root) (root<<1)+1

template<typename T, T join(T, T)>
struct segtree {
    T* seg; int N;

    void _build(int l, int r, T *v, int root = 1) {
        if(l == r)
            seg[root] = v[l];
        else {
            int m = (l+r)/2;
            _build(l, m, v, sx(root));
            _build(m+1, r, v, dx(root));
            seg[root] = join(seg[sx(root)], seg[dx(root)]);
        }
    }
    segtree(int N) {this->N = N, seg = new T[4*N];}
    segtree(T v[], int N):segtree{N} { _build(0, N-1, v);}
    ~segtree() {delete[] seg;}

    void _set(int l, int r, int p, T v, int root=1) {
        if(p < l || p > r) return;
        if(l == r) { seg[root] = v; return;}
        int m = (l+r)/2;
        if(p>m)
            _set(m+1, r, p, v, dx(root));
        else
            _set(l, m, p, v, sx(root));
        seg[root] = join(seg[sx(root)], seg[dx(root)]);
    }

    void set(int p, T v) {_set(0, N-1, p, v);}
    T _query(int l, int r, int _s, int _e, int root=1) {
        if(_s <= l && r <= _e) return seg[root];
        int m = (l+r)/2;
        if(_s > m)
            return _query(m+1, r, _s, _e, dx(root));
        else if(_e <= m)
            return _query(l, m, _s, _e, sx(root));
        return join(_query(l, m, _s, _e, sx(root)),
                    _query(m+1, r, _s, _e, dx(root)));
    }
    T query(int s, int e) {return _query(0, N-1, s, e);}
};

struct maxsum {
    int l, r, max, sum;
    maxsum()=default;
    maxsum(int v) {l=r=max=sum=v;}
    maxsum(int le, int ri, int ma, int s) {l=le, r=ri, max=ma, sum=s;}
};

maxsum Join(maxsum a, maxsum b) {
    return maxsum(std::max(a.l, a.sum + b.l), std::max(b.r, b.sum + a.r), std::max(std::max(a.sum + b.sum, a.r + b.l), std::max(a.max, b.max)), a.sum + b.sum);
}

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
        ch = getchar_unlocked();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}

using namespace std;

int main()
{
    // per il CMS - su SPOJ non è definito AFAIK
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int N = readInt();
    segtree<maxsum, Join> V(N);
    for(int i = 0; i < N; i++) V.set(i, readInt());
    int Q, a, b, c;
    Q = readInt();
    while(Q--){
        a = readInt(), b = readInt(), c = readInt();
        if(a) printf("%d\n", V.query(b-1, c-1).max);
        else V.set(b-1, c);
    }
}
