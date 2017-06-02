#include <bits/stdc++.h>

#define MAX_N 500001
using namespace std;

int N, M;

static struct {
    int v[MAX_N+1];
    void update(int idx, int val) {do v[idx]+=val; while((idx += (idx & -idx)) <= N);}
    int query(int idx) {int r = 0; do r += v[idx]; while(idx -= (idx & -idx)); return r;}
} fenwick;


vector<int> figli[MAX_N];
int preorder[MAX_N];
int employee2preidx[MAX_N];
int initialwage[MAX_N];
int boss[MAX_N];

int pre_tmp = 1;
int last_preorder[MAX_N];

void make_preorder(int v)
{
    employee2preidx[v] = pre_tmp;
    preorder[pre_tmp++] = v;
    for(int i: figli[v])
        make_preorder(i);
    last_preorder[v] = pre_tmp;
}

void raise(int employee, int wageinc)
{
    int preidx = employee2preidx[employee];
    fenwick.update(preidx+1, wageinc);
    fenwick.update(last_preorder[employee], -wageinc);
}

int query(int employee)
{
    return fenwick.query(employee2preidx[employee]);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d %d %d", &N, &M, initialwage + 1);
    for(int i = 2; i <= N; i++) {
        int wage, b;
        scanf("%d %d", &wage, &b);
        initialwage[i] = wage;
        figli[b].push_back(i);
        boss[i] = b;
    }
    make_preorder(1);
    while(M--) {
        char ch; int employee, incwage;
        scanf(" %c %d", &ch, &employee);
        if(ch == 'u')
            printf("%d\n", initialwage[employee] + query(employee));
        else {
            scanf("%d", &incwage);
            raise(employee, incwage);
        }
    }
}
