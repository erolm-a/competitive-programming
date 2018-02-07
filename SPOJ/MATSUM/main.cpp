// 2D Segment Tree - just 0.90s

#include <cstdio>
#include <cstring>

#define sx(root) root<<1
#define dx(root) (root<<1)+1

using namespace std;

#define MAX_N 1024
int segtree[4*MAX_N][4*MAX_N];
int N;

int modified;

int query_1d(int x1, int x2, int l, int r, int root, int *seg) {
    if(x1<=l && r <= x2) return seg[root];
    int m = (l+r)/2;
    if(x1 > m) return query_1d(x1,x2,m+1,r,dx(root), seg);
    else if(x2 <= m) return query_1d(x1,x2,l,m, sx(root), seg);
    return query_1d(x1,x2,m+1,r,dx(root), seg) + query_1d(x1,x2,l,m,sx(root), seg);
}
int query(int x1, int y1, int x2, int y2, int l, int r, int r1) {
    if(y1<=l && r <= y2) return query_1d(x1,x2,0,N-1,1,segtree[r1]);
    int m = (l+r)/2;
    if(y1 > m) return query(x1, y1, x2, y2, m+1, r, dx(r1));
    else if(y2 <= m) return query(x1, y1, x2, y2, l, m, sx(r1));
    return query(x1, y1, x2, y2, m+1, r, dx(r1)) + query(x1, y1, x2, y2, l, m, sx(r1));
}
void set_1d(int x, int v, int l, int r, int root, int* seg) {
    if(l==r) {modified = (seg[root]=v,root); return;}
    int m = (l+r)/2;
    if(x > m) set_1d(x,v,m+1,r,dx(root),seg);
    else set_1d(x,v,l,m,sx(root),seg);
    seg[root] = seg[sx(root)] + seg[dx(root)];
}
void set(int x, int y, int v, int l, int r, int r1)
{
    if(l == r) {set_1d(x,v,0,N-1,1,segtree[r1]); return;}
    int m = (l+r)/2;
    if(y>m) set(x,y,v,m+1,r,dx(r1));
    else set(x,y,v,l,m,sx(r1));
    for(int t = modified; t > 0; t>>=1)
        segtree[r1][t] = segtree[sx(r1)][t] + segtree[dx(r1)][t];
}

int main()
{
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        scanf(" %d", &N);
        for(int i = 1; i < 4*N; i++)
            memset(segtree[i], 0, sizeof(int)*4*N);
        while(true) {
            char command[4];
            scanf(" %s", command);
            if(strcmp("END", command) == 0) break;
            if(strcmp("SUM", command) == 0) {
                int x1, x2, y1, y2;
                scanf(" %d %d %d %d", &x1, &y1, &x2, &y2);
                printf("%d\n", query(x1,y1,x2,y2,0,N-1,1));
            }
            else {
                int x, y, v;
                scanf(" %d %d %d", &x, &y, &v);
                set(x,y,v,0,N-1,1);
            }
        }
        puts("");
    }
}
