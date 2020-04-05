#include <bits/stdc++.h>

using namespace std;


#define sx(root) root<<1
#define dx(root) (root<<1)+1

#define MAX_N 10

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

    void build(T* v, int N) {this->N = N, seg = new T[4*N]; _build(0, N-1, v);}
    segtree()=default;
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

template<typename Int>
Int readInteger () {
    bool minus = false;
    Int result = 0;
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

#define readint readInteger<int>

vector<int> studenti[MAX_N];
int bugs[MAX_N];

int N, M, S;

bool compare(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];
}
vector<int> join(vector<int>a, vector<int> b) {
    if(a[2] < b[2])
        return b;
    return a;
}

segtree<vector<int>, join> cerca_minimo;

vector<int> presi[MAX_N];
bool possibile(int giorni)
{
    // cerchiamo il range di studenti capaci

    int Mt = M-1;
    int sum = 0;

    for(int i = 0; i < N; i++)
        presi[i].clear();

    while(Mt >= 0) {
        int h = (upper_bound(studenti, studenti + N, vector<int>{0, bugs[Mt], 0}, compare) - studenti) - 1;
        int l = (lower_bound(studenti, studenti + N, vector<int>{0, bugs[Mt], 0}, compare) - studenti);
        auto x = cerca_minimo.query(l, h);
        int scelta = x[0];
        sum += x[2];
        if(sum > S) return false;
        while(presi[scelta].size() < giorni && M >= 0)
            presi[scelta].push_back(bugs[Mt--]);
    }
    return true;
}
int main()
{
    //freopen("input.txt", "r", stdin);

    scanf("%d %d %d", &N, &M, &S);

    for(int i = 0; i < M; i++)
        bugs[i] = readint();

    for(int i = 0; i < N; i++) {
        studenti[i].resize(3);
        studenti[i][0] = i;
        studenti[i][1] = readint();
    }
    for(int i = 0; i < N; i++)
        studenti[i][2] = readint();


    sort(studenti, studenti + N, compare);
    sort(bugs, bugs + M);

    cerca_minimo.build(studenti, N);

    int l = 1, h = M;

    if(!possibile(M)) {
        printf("NO\n");
        return 0;
    }
    while(h - l > 1) {
        int m = (h+l)/2;
        if(possibile(m))
            h = m;
        else l = m;
    }

    printf("SI\n", h);
}
