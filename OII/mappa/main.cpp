#include <cstdio>
#include <queue>
#include <algorithm>
#include <utility>

#define MAX_N 101
char mappa[MAX_N][MAX_N+1];
int N;

using namespace std;

int dists[MAX_N][MAX_N];

using coords = pair<int, int>;
using state = pair<int, coords>;

#define valid(a, b, c) a >= 0 && a < N && \
    b >= 0 && b < N && mappa[a][b] == '*' \
    && c < dists[a][b]

int bfs()
{
    fill(dists[0], dists[MAX_N], 10001);
    dists[0][0] = 1;

    queue<state> bfs_queue;
    bfs_queue.push(make_pair(1, make_pair(0, 0)));
    coords end = coords(N-1, N-1);

    while(!bfs_queue.empty())
    {
        state p = bfs_queue.front();
        int d = p.first;
        coords cd = p.second;
        bfs_queue.pop();
        if(cd == end)
            return p.first;
        if(valid(cd.first, cd.second+1, d+1)) {
            dists[cd.first][cd.second+1] = d+1;
            bfs_queue.push(state(d+1, coords(cd.first, cd.second+1)));
        }
        if(valid(cd.first, cd.second-1, d+1)) {
            dists[cd.first][cd.second-1] = d+1;
            bfs_queue.push(state(d+1, coords(cd.first, cd.second-1)));
        }
        if(valid(cd.first+1, cd.second, d+1)) {
            dists[cd.first+1][cd.second] = d+1;
            bfs_queue.push(state(d+1, coords(cd.first+1, cd.second)));
        }
        if(valid(cd.first-1, cd.second, d+1)) {
            dists[cd.first-1][cd.second] = d+1;
            bfs_queue.push(state(d+1, coords(cd.first-1, cd.second)));
        }
        if(valid(cd.first+1, cd.second+1, d+1)) {
            dists[cd.first+1][cd.second+1] = d+1;
            bfs_queue.push(state(d+1, coords(cd.first+1, cd.second+1)));
        }
        if(valid(cd.first+1, cd.second-1, d+1)) {
            dists[cd.first+1][cd.second-1] = d+1;
            bfs_queue.push(state(d+1, coords(cd.first+1, cd.second-1)));
        }
        if(valid(cd.first-1, cd.second+1, d+1)) {
            dists[cd.first-1][cd.second+1] = d+1;
            bfs_queue.push(state(d+1, coords(cd.first-1, cd.second+1)));
        }
        if(valid(cd.first-1, cd.second-1, d+1)) {
            dists[cd.first-1][cd.second-1] = d+1;
            bfs_queue.push(state(d+1, coords(cd.first-1, cd.second-1)));
        }
    }
    return -1;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%s", mappa[i]);

    printf("%d\n", bfs());
}
