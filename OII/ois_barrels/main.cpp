#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_N 1000000
#define sx(root) (root<<1)
#define dx(root) ((root<<1)+1)
long long captree[4*MAX_N], full[4*MAX_N], lazy[4*MAX_N];

long long caps[MAX_N];
void build(int l, int r, int root=1)
{
    if(l==r) {captree[root] = caps[l]; return;}
    int m = (l+r)/2;
    build(l,m,sx(root)); build(m+1,r,dx(root));
    captree[root] = captree[sx(root)]+captree[dx(root)];
}

long long set(long long k, int u, int l, int r, int root=1) {
    if(lazy[root]) {
        int surplus = max(0ll, lazy[root] + full[root] - captree[root]);
        k += surplus;
        lazy[root] -= surplus;
        full[root] += lazy[root];
        int s = min(lazy[root], captree[sx(root)] - full[sx(root)] - lazy[sx(root)]);
        lazy[sx(root)] += s;
        lazy[dx(root)] += lazy[root] - s;
        lazy[root] = 0;
    }
    if(!k) return 0;
    if(l >= u) {
        lazy[root] = min(k, captree[root]-full[root]);
        return k-lazy[root];
    }
    int m = (l+r)/2;
    long long ris = 0;

    if(u > m) ris = set(k,u,m+1,r,dx(root));
    else ris = set(set(k,u,l,m,sx(root)),u,m+1,r,dx(root));
    full[root] = full[sx(root)] + full[dx(root)];
    return ris;
}

long long query(int u, int l, int r, int root=1) {
    if(lazy[root]) {
        int surplus = max(0ll, lazy[root] + full[root] - captree[root]);
        lazy[root] -= surplus;
        full[root] += lazy[root];
        int s = min(lazy[root], captree[sx(root)] - full[sx(root)] - lazy[sx(root)]);
        lazy[sx(root)] += s;
        lazy[dx(root)] += lazy[root] - s;
        lazy[root] = 0;
    }
    if(l==r) return full[root];
    int m = (l+r)/2;
    long long ris;
    if(u > m) ris = query(u,m+1,r,dx(root));
    else ris = query(u,l,m,sx(root));
    full[root] = full[sx(root)] + full[dx(root)];
    return ris;
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
        scanf("%lld", caps + i);

    build(0, N-1);
    while(M--) {
        long long p1, p2; char command;
        scanf(" %c %lld", &command, &p1);
        if(command == 'M')
            printf("%lld\n", query(p1, 0, N-1));
        else {scanf("%lld", &p2); set(p1,p2,0,N-1);}
    }
}
