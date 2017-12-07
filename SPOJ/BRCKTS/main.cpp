#include <bits/stdc++.h>

using namespace std;

#define dx(root) (root<<1)+1
#define sx(root) root<<1
template<typename T, T join(T&, T&)>
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
    segtree(int N) {seg = new T[4*N];}
    segtree(T v[], int N) {this->N = N, seg = new T[4*N]; _build(0, N-1, v);}
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
//    T _query(int l, int r, int _s, int _e, int root=1) {
//        if(l <= _s && r <= _e) return seg[root];
//        int m = (l+r)/2;
//        if(_s > m)
//            return query(m+1, r, _s, _e, dx(root));
//        else if(_e < l)
//            return query(l, m, _s, _e, sx(root));
//        return join(query(l, m, _s, _e, sx(root)),
//                    query(m+1, r, _s, _e, dx(root)));
//    }
//    T query(int s, int e) {return _query(0, N-1, s, e);}
};

struct minprefix {
    int pref, sum;

    minprefix()=default;
    minprefix(int p, int s) {pref = p, sum = s;}
    minprefix(char a) {if(a == '(') pref = 0, sum = 1; else pref = sum = -1;}
};

minprefix join(minprefix& a, minprefix& b) {return {min(a.pref, a.sum + b.pref),a.sum + b.sum};}

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

#define MAX_N 30002
char buf[MAX_N];

char invert(char ch)  {return ch == '(' ? ')' : '(';}
int main() {

    int i = 0;
    segtree<minprefix, join> a(MAX_N);
    while(i++ < 10) {
        int n = readInt();
        scanf(" %s", buf);
        int m = readInt();
        vector<int> q;
        while(m--)
            q.push_back(readInt());

        minprefix nums[MAX_N];
        for(int i = 0; i < n; i++)
            nums[i] = minprefix(buf[i]);

        a.N = n;
        a._build(0, n-1, nums);

        printf("Test %d:\n", i);
        for(int qu: q)
            if(qu == 0) {
                auto ris = a.seg[1];
                puts(ris.sum == 0 && ris.pref >= 0 ? "YES" : "NO");
            }
            else
                a.set(qu-1, minprefix(buf[qu-1] = invert(buf[qu-1])));
    }
}
