#include <bits/stdc++.h>

using namespace std;

#define MAX_N 500000

int N;
struct {
    int v[MAX_N+1];
    void update(int idx, int val) {do{v[idx]+=val;}while((idx += (idx & -idx)) <= N);}
    int query(int idx) {int ris = 0; do{ris+=v[idx];}while(idx -= (idx & -idx)); return ris;}
} fenwick;

int preorder[MAX_N+2];
int pos_preorder[MAX_N + 2];
vector<int> grafo[MAX_N+1];
int paga_orig[MAX_N+1];
int last_preorder[MAX_N+2];
void make_preorder(int s, int &i)
{
    preorder[i++] = s;
    for(int j: grafo[s])
        make_preorder(j, i);
    last_preorder[s] = i;
}


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int M;
    scanf("%d %d %d", &N, &M, paga_orig + 1);
    for(int i = 2; i <= N; i++) {
        int c, sup;
        scanf("%d %d", &c, &sup);
        paga_orig[i] = c;
        grafo[sup].push_back(i);
    }
    // preorder
    int temp = 1;
    make_preorder(1, temp);
    for(int i = 1; i <= temp; i++)
        pos_preorder[preorder[i]] = i;

    fprintf(stderr, "Preorder: ");
    for(int i = 1; i <= N; i++)
        fprintf(stderr, "%d ", preorder[i]);
    fputs("\n", stderr);

    // calcolo vero e proprio
    while(--M>=0)
    {
        char s;
        int A;
        scanf(" %c %d", &s, &A);
        if(s == 'p') {
            int X;
            scanf("%d", &X);
            fenwick.update(pos_preorder[A]+1, X);
            fenwick.update(last_preorder[A], -X);
            fprintf(stderr, "%d\n", fenwick.query(pos_preorder[A]));
        }
        else
            printf("%d\n", paga_orig[A] + fenwick.query(pos_preorder[A]) -
                   fenwick.query(pos_preorder[A] - 1));
    }
}
