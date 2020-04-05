#include <bits/stdc++.h>

using namespace std;

#define sx(root) root<<1
#define dx(root) (root<<1)+1

#define MAX_N 100000
static int nums[MAX_N], N, Q;

// coordinate compression
static map<int, int> compress;

// segment tree
static vector<int> tree[4*MAX_N];

void compress_coordinate()
{
    vector<int> sorted(nums, nums + N);
    sort(sorted.begin(), sorted.end());

    for(int i = 0; i < N; i++)
        compress[sorted[i]] = i+1;

    for(int& num: nums)
        num = compress[num];
}

void build(int root, int l, int r)
{
    tree[root].resize(r-l+1);
    if(l == r) {
        tree[root][0] = nums[l-1];
        return;
    }

    int m = (l+r)/2;
    build(sx(root), l, m);
    build(dx(root), m+1, r);

    merge(tree[sx(root)].begin(), tree[sx(root)].end(),
            tree[dx(root)].begin(), tree[dx(root)].end(),
            tree[root].begin());
}

void build() {build(1, 1, N);}

pair<int,bool> query(int root, int l, int r, int start, int end, int k) {
    if(start <= l && r <= end) {
        auto found = upper_bound(tree[root].begin(), tree[root].end(), k);
        if(found != tree[root].begin())
            return {found - tree[root].begin(), *(found-1) == k};
        else return {0, false};
    }

    int m = (l+r)/2;
    int res = 0; bool wasfound = false;

    if(start <= m) {
        auto t = query(sx(root), l, m, start, end, k);
        res += t.first, wasfound |= t.second;
    }
    if(end > m) {
        auto t = query(dx(root), m+1, r, start, end, k);
        res += t.first, wasfound |= t.second;
    }

    return {res, wasfound};
}

int kth_minimum(int start, int end, int k)
{
    // if a node is a kth-minimum then it should have k-1 predecessors
    int l = 1, r = N+1;

    while(r != l) {
        int m = (l+r)/2;
        auto ris = query(1, 1, N, start, end, m);
        if(ris.first == k && ris.second) return m;

        else if(ris.first <= k)
            l = m;
        else
            r = m;
    }
    return -1;
}

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
int main()
{
    N = readint();
    Q = readint();

    for(int i = 0; i < N; i++)
        nums[i] = readint();

    compress_coordinate();
    build();

    for(int i = 0; i < Q; i++) {
        int l, r, k;
        l = readint(); r = readint(); k = readint();
        printf("%d\n", kth_minimum(l, r, k));
    }
}
