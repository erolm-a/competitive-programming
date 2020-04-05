#include <bits/stdc++.h>

using namespace std;
#define MAX_N 10001
vector<pair<int, int>> adj_list[MAX_N];
int depth[MAX_N], ancestor[MAX_N][20], subtreesz[MAX_N];

#define sx(root) root<<1
#define dx(root) (root<<1)+1

template<typename T, T (*join)(T, T)>
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
int join(int a, int b) {return max(a, b);}
// edge2chain is a list of chains
vector<vector<int>> edge2chain; vector<segtree<int, join>> chains;
int root, color[MAX_N];

void dfs(int x) {
    subtreesz[x] = 1;
    for(auto p: adj_list[x])
        if(ancestor[p.second][0] == -1 && p.second != root) {
            ancestor[p.second][0] = x;
            int i = 1;
            do
                ancestor[p.second][i] = ancestor[ancestor[p.second][i-1]][i-1];
            while (ancestor[p.second][i] != -1);
            depth[p.second] = depth[x] + 1;
            dfs(p.second);
            subtreesz[x] += subtreesz[p.second];
        }
}

void hld(int x, int chain = 0) {
    if(adj_list[x].size() == 0)
        return;
    if(chain + 1 > edge2chain.size())
        edge2chain.push_back({});
    color[x] = chain;

    if(adj_list[x].size()) {
        pair<int, int> best_edge = adj_list[x][0];

        for(auto p: adj_list[x])
            if(subtreesz[best_edge.second] < subtreesz[p.second])
                best_edge = p;

        hld(best_edge.second, chain);

        for(auto p: adj_list[x]) {
            edge2chain[color[p.second]].push_back(p.first);
            if(p != best_edge)
                hld(p.second, ++chain);
        }
    }
}

void init_hld(int root) {
    ::root = root;
    hld(root);
    for(int c = 0; c < edge2chain.size(); c++)
        chains.emplace_back(edge2chain[c].data(), edge2chain[c].size());
}


inline void step(int& x, int size) {
    while(size) {
        int jmp = __builtin_ctz(size);
        x = ancestor[x][jmp];
        size -= jmp;
    }
}

int lca(int a, int b) {
    if(depth[a] < depth[b])
        swap(a, b);
    step(b, depth[b] - depth[a]);
    while(a != b) {
        int po = 19;
        if(ancestor[a][0] == ancestor[b][0])
            return ancestor[a][0];
        while(ancestor[a][po] == ancestor[b][po])
            po--;
        a = ancestor[a][po]; b = ancestor[b][po];
    }
    return a;
}

// b is the ancestor of a
int query_helper(int a, int b) {
    if(a == b) return 0;

    int sol = INT_MIN;

    while(a != b) {
        int top_chain = edge2chain[color[a]][0];

        if(top_chain != a) {
            // query to get the value we are looking for
        }
    }
}

int main()
{

}
