#include <bits/stdc++.h>

using namespace std;
#define MAX_K 10
#define MAX_N 30000
long long dists[MAX_K][MAX_N];
long long sum[MAX_N];

long long D[MAX_K], P[MAX_K], N, M, K;

using pii = pair<long long, long long>;
vector<pii> grafo[MAX_N];

long long minimo = numeric_limits<long long>::max();
long long occ;

void dijkstra(long long src)
{
    long long coeff = P[src];
    if(coeff == 0)
        return;
    fill(dists[src], dists[src] + N, numeric_limits<long long>::max());
    dists[src][D[src]] = 0;
    pii start = make_pair(0, D[src]);
    priority_queue<pii, vector<pii>, greater<pii>> states;
    states.push(start);

    while(!states.empty())
    {
        pii p = states.top();
        states.pop();
        for(pii &x: grafo[p.second])
            if(x.first*coeff + p.first < dists[src][x.second])
            {
                dists[src][x.second] = x.first*coeff + p.first;
                states.push(make_pair(dists[src][x.second], x.second));
            }
    }
}

void calc() {
    for(long long i = 0; i < K; i++)
        dijkstra(i);
    for(long long i = 0; i < N; i++) {
        for(long long j = 0; j < K; j++)
            sum[i]+=dists[j][i];
        if(sum[i] < minimo)
            minimo = sum[i], occ = 1;
        else if(sum[i] == minimo) occ++;
    }
}

long long main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long M;
    scanf("%d %d %d", &N, &M, &K);
    for(long long i = 0; i < K; i++)
        scanf("%d", D + i);
    for(long long i = 0; i < K; i++)
        scanf("%d", P + i);

    while(M--)
    {
        long long a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        grafo[a].push_back(make_pair(c, b));
        grafo[b].push_back(make_pair(c, a));
    }
    calc();
    printf("%d\n%lld", occ, minimo);
}
