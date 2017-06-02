#include <bits/stdc++.h>

using namespace std;

#define MAX_N 50000
int N;

int st[MAX_N*2];
bool summable[MAX_N*2];
int nums[MAX_N+1];

void build(int root, int l, int r)
{
    if(l == r) {
        st[root] = nums[l];
        summable[root] = nums[l] >= 0;
    }
    else {
        int mid = (l+r)/2;
        build(root*2+1, l, mid);
        build(root*2+2, mid+1, r);
        int cr = root*2+1 + root%2;
        int s = st[root*2+1] + st[root*2+2];
        if(summable[cr]) {
            if(root > 0) st[root] = max(st[cr], s);
            else st[root] = max(s, max(st[root*2+1], st[root*2+2]));
            summable[root] = 1;
        }
        else st[root] = max(st[root*2+1], st[root*2+2]), summable[root] = 0;
    }
}

void update(int root, int l, int r, int idx, int val)
{
    if(idx < l || idx > r) return;
    if(l == r)
        st[root] = nums[idx] = val, summable[root] = nums[idx] >= 0;
    else {
        int mid = (l+r)/2;
        update(root*2+1, l, mid, idx, val);
        update(root*2+2, mid+1, r, idx, val);
        int cr = root*2+1 + root%2;
        int s = st[root*2+1] + st[root*2+2];
        if(root > 0 && summable[cr]) {
            if(root > 0) st[root] = max(st[cr], s);
            else st[root] = max(s, max(st[root*2+1], st[root*2+2]));
            summable[root] = 1;
        }
        else if(root == 0)
            st[root] = summable[1] && summable[2] ? st[1] + st[2] : max(st[1], st[2]);
        else st[root] = max(st[root*2+1], st[root*2+2]), summable[root] = 0;
    }
}

int query(int root, int l, int r, int start, int end)
{
    if(start > r || end < l)
        return INT_MIN/3;
    if(start <= l && end >= r)
        return st[root];
    int mid = (l+r)/2;
    int ch[] = {query(root*2+1, l, mid, start, end), query(root*2+2, mid+1, r, start, end)};
    int s = ch[0] + ch[1];
    int cr = root%2;
    if((root > 0 && summable[root*2+1+cr]) ||
            (root == 0 && summable[1] && summable[2]))
        return max(s, max(ch[0], ch[1]));
    else return max(ch[0], ch[1]);
}

int readint() {
    int c, n = 0; bool neg = false;
    while((c = getchar_unlocked()) != -1 && !isspace(c))
        if(c == '-') neg=true;
        else n = n*10 + c - '0';
    return neg ? -n : n;
}

char read_stripped_char() {
    char ch;
    while(isspace(ch = getchar_unlocked()));
    return ch;
}

int main()
{
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);

    N = readint();
    for(int i = 1; i <= N; i++)
        nums[i] = readint();
    build(0, 1, N);
    int M = readint();
    while(M--) {
        int ch = readint(), x = readint(), y = readint();
        switch(ch) {
            case 0: update(0, 1, N, x, y); break;
        case 1: printf("%d\n", query(0, 1, N, x, y));
        }
    }
    return 0;
}
