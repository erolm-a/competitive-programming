#include <bits/stdc++.h>

using namespace std;
#define MAX_N 50000
#define MAX_K 1000000
#define MAX_T 100000

struct path {
    int a, b, w;
    bool operator<(const path& other) const {return w > other.w;}
} paths[MAX_K];

int N, K, T;
int tc[MAX_T], wt[MAX_T];
int res[MAX_N+1];

// UFDS

struct UFDS {
    int parent[MAX_N+1], rank[MAX_N+1], sets;

    UFDS(): sets{N} {iota(parent+1, parent + N+1, 1);}

    int findset(int a) {return (parent[a] == a ? a : (parent[a] = findset(parent[a])));}
    bool sameset(int a, int b) {return findset(a) == findset(b);}
    void joinset(int a, int b) {
        int x = findset(a), y = findset(b);
        if(rank[x] > rank[y]) parent[y] = x;
        else {parent[x] = y; if(rank[x] == rank[y]) rank[y]++;}
        sets--;
    }
};


int main()
{
    scanf("%d %d %d", &N, &K, &T);
    UFDS ufds;


    for(int i = 0; i < K; i++)
        scanf(" %d %d %d", &paths[i].a, &paths[i].b, &paths[i].w);

    sort(paths, paths + K);

    for(int i = 0; i < T; i++)
        scanf(" %d", tc + i);

    memcpy(wt, tc, T*sizeof(int));

    sort(wt, wt + T, greater<int>());

    int p = 0;
    for(int t = 0; t < T; t++) {
        while(p<K && wt[t] <= paths[p].w) {
            if(!ufds.sameset(paths[p].a, paths[p].b))
                ufds.joinset(paths[p].a, paths[p].b);
            p++;
        }
        res[wt[t]] = ufds.sets;
    }

    for(int i = 0; i < T; i++)
        printf("%d\n", res[tc[i]]);
}
