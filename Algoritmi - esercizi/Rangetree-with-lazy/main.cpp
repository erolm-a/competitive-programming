#include <iostream>
#include <limits>

// implementazione di una RSQ con lazy-tree
using namespace std;
#define MAX_N 1000
int st[2*MAX_N];
int lazy[2*MAX_N];

int nums[MAX_N] = {3, 4, 2, 4, 1, 5};

int tmp_num_l;
void build(int root, int start, int end)
{
    if(end - start == 1)
        st[root] = nums[tmp_num_l++];
    else {
        int m = (end + start) / 2;
        build(root*2+1, start, m);
        build(root*2+2, m, end);
        st[root] = st[root*2+1] + st[root*2+2];
    }
}

// classico
int query(int root, int start, int end, int q_l, int q_r)
{
    if(q_l >= end || q_r <= start)
        return 0;
    else if(start >= q_l && end <= q_r)
        return st[root];
    int m = (end + start)/2;
    return query(root*2+1, start, m, q_l, q_r) + query(root*2+2, m, end, q_l, q_r);
}

void update(int root, int start, int end, int idx, int val)
{
    if(idx < start || idx >= end)
        return;
    if(end - start == 1) {
        st[root] = val; return;
    }
    int m = (end+start)/2;
    update(root*2+1, start, m, idx, val);
    update(root*2+2, m, end, idx, val);
    st[root] = st[root*2+1] + st[root*2+2];
}

void updaterange(int root, int start, int end, int q_l, int q_r, int diff) {
    if(q_l >= end || q_r <= start)
        return;
    if(lazy[root]) {
        st[root] = lazy[root]*(end - start);
        if(end - start > 1)
            lazy[root*2+1] += lazy[root], lazy[root*2+2] += lazy[root];
        lazy[root] = 0;
    }
    if(q_l >= start && q_r<= end) {
        st[root]+=(end-start)*diff;
        if(end - start > 1) lazy[root*2+1]+=diff,lazy[root*2+2]+=diff;
        return;
    }
    int m = (end+start) / 2;
    updaterange(root*2+1, start, m, q_l, q_r, diff);
    updaterange(root*2+2, m, end, q_l, q_r, diff);

    st[root] = st[root*2+1] + st[root*2+2];
}

int queryrange(int root, int start, int end, int q_l, int q_r)
{
    if(lazy[root]) {
        st[root] += lazy[root]*(end-start);
        if(end - start > 1)
            lazy[root*2+1] += lazy[root], lazy[root*2+2] += lazy[root];
        lazy[root] = 0;
    }
    if(q_l >= end || q_r <= start)
        return 0;

    if(start >= q_l && end <= q_r)
        return st[root];
    int m = (end + start) / 2;
    return queryrange(root*2+1, start, m, q_l, q_r) +
            queryrange(root*2+2, m, end, q_l, q_r);
}

int main()
{
    build(0, 0, 6);
    for(int i = 0; i <= 5; i++) {
        for(int j = i+1; j <= 6; j++)
            printf("%d ", query(0, 0, 6, i, j));
        puts("");
    }
    updaterange(0, 0, 6, 2, 5, 4);
    for(int i = 0; i <= 5; i++) {
        for(int j = i+1; j <= 6; j++)
            printf("%d ", queryrange(0, 0, 6, i, j));
        puts("");
    }
}
