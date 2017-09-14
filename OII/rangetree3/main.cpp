#include <bits/stdc++.h>

// CREDITS: Luca Cavalleri per il suo segment tree... molto migliore
// della mia robaccia obbrobriosa

template<typename T, T join(T, T)>
struct segtree {
    int _l, _r, _m;
    segtree *_left, *_right;
    T _val;
    segtree(int l, int r, T k=T()) {
        if(l == r) {
            _l=_m=_r=l;
            _val=k;
            _left = _right = nullptr;
        }
        else {
            _l=l,_r=r;_m = (l+r)/2;
            _left = new segtree(_l,_m,k),_right = new segtree(_m+1,_r,k);
            _val = join(_left->_val, _right->_val);
        }
    }
    void set(int p, T v)
    {
        if(_l == _r) {_val = v; return;}
        if(p>_m) _right->set(p, v); else _left->set(p, v);
        _val = join(_left->_val, _right->_val);
    }

    T query(int s, int e) {
        if(_l>=s && _r<=e) return _val;
        if(s>_m) return _right->query(s, e);
        if(e <= _m) return _left->query(s, e);
        return Join(_left->query(s, e), _right->query(s, e));
    }
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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N = readInt();
    segtree<maxsum, Join> V(1, N);
    for(int i = 1; i <= N; i++) V.set(i, readInt());
    int Q, a, b, c;
    Q = readInt();
    while(Q--){
        a = readInt(), b = readInt(), c = readInt();
        if(a) printf("%d\n", V.query(b, c).max);
        else V.set(b, c);
    }
}
