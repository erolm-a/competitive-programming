#include <bits/stdc++.h>

#define MAX_N 200010
#define MAX_Q 8*MAX_N

int N, Q;
using namespace std;

using ll = long long;

struct fenwick {
    int tree[MAX_N];
    void update(int idx) {
        while(idx <= N+1) {
            tree[idx]++;
            idx += (idx & -idx);
        }
    }
    int query(int idx) {
        int sum = 0;
        while(idx > 0) {
            sum += tree[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }
} f1, f2;


// value => index, starting from 1
pair<int, int> elems[MAX_N];

// query
struct query {
    int l, d, r, u; bool skip;
} queries[MAX_Q];

struct query2 {
    int x, l, r, idx; bool skip;
    bool operator<(const query2& other) {return x < other.x;}
} query_upper[MAX_Q], query_lower[MAX_Q];

long long sols_upper[MAX_Q], sols_lower[MAX_Q];

bitset<MAX_Q> skip;

#define check(x,y) (x >= 1 && x <= N && y >= 1 && y <= N && x <= y)

void preprocess() {
    sort(elems+1, elems+N+1);

    for(int q = 0; q < 8*Q; q++) {
        query_upper[q] = {queries[q].u, queries[q].l, queries[q].r, q};
        query_lower[q] = {queries[q].d, queries[q].l, queries[q].r, q};
        if(!check(queries[q].d, queries[q].u) || !check(queries[q].l, queries[q].r))
            query_upper[q].skip = query_lower[q].skip = queries[q].skip = true;
    }
    sort(query_upper, query_upper + 8*Q);
    sort(query_lower, query_lower + 8*Q);
}

void find_lower() {
    int i = 1;

    for(int q = 0; q < 8*Q; q++) {
        if(query_lower[q].skip) continue;
        for(; i <= N && elems[i].first < query_lower[q].x; i++)
            f1.update(elems[i].second);

        sols_lower[query_lower[q].idx] = f1.query(query_lower[q].r) -
                                         f1.query(query_lower[q].l-1);
    }
}

void find_upper() {
    int i = N;

    for(int q = 8*Q-1; q >= 0; q--) {
        if(query_upper[q].skip) continue;
        for(; i > 0 && elems[i].first > query_upper[q].x; i--)
            f2.update(elems[i].second);

        sols_upper[query_upper[q].idx] = f2.query(query_upper[q].r) -
                                         f2.query(query_upper[q].l-1);
    }
}

inline long long solve_ith(int i) {
    if(queries[i].skip)
        return 0;

    return queries[i].r - queries[i].l+1 - sols_lower[i] - sols_upper[i];
}

inline long long comb(long long n) {return n*(n-1)/2;}

int main() {
    scanf("%d %d", &N, &Q);
    for(int i = 1; i<=N; elems[i].second = i, i++)
        scanf("%d", &elems[i].first);

    for(int q = 0; q < 8*Q; q+=8) {
        int l, d, r, u;

        scanf("%d %d %d %d", &l, &d, &r, &u);

        // top row
        queries[q] = {1, u+1, N, N};
        // bottom row
        queries[q+1] = {1, 1, N, d-1};
        // left row
        queries[q+2] = {1, 1, l-1, N};
        // rigth row
        queries[q+3] = {r+1, 1, N, N};
        // top-left
        queries[q+4] = {1, u+1,l-1, N};
        // top-right
        queries[q+5] = {r+1, u+1, N, N};
        // bottom-left
        queries[q+6] = {1, 1, l-1, d-1};
        // bottom-right
        queries[q+7] = {r+1, 1, N, d-1};

    }

    preprocess();
    find_lower();
    find_upper();

    for(int i = 0; i < 8*Q; i+=8) {
        auto top = solve_ith(i),
        bottom = solve_ith(i+1),
        left = solve_ith(i+2),
        right = solve_ith(i+3),
        tl = solve_ith(i+4),
        tr = solve_ith(i+5),
        bl = solve_ith(i+6),
        br = solve_ith(i+7);

        printf("%lld\n", comb(N)-comb(top)-comb(bottom)-comb(left)-comb(right)+comb(tr)+comb(tl)+comb(bl)+comb(br));
    }
}
