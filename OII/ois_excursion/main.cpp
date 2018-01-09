#include <bits/stdc++.h>
#define MAXX 2000

using namespace std;

#define check(h, w) (h >= 0 && h < H && w >= 0 && w < W)
#define check2(h, w) (check(h, w) && !(h == prec_h && w == prec_w))
#define check3(h, w) \
    if(check2(h, w)) { \
        int diff = abs(A[cur_h][cur_w] - A[h][w]); \
        if((best_diff > diff) || \
                (best_diff == diff && A[next_h][next_w] > A[h][w])) \
                    best_diff = diff, next_h = h, next_w = w; \
       }

int H, W;
int A[MAXX][MAXX];
int dists[MAXX][MAXX];
bitset<MAXX> visited[MAXX];


int hike() {
    int cur_h = 0, cur_w = 0, prec_h = -1, prec_w = -1;

    int steps = 0;
    while(true) {
        if(visited[cur_h][cur_w])
            break;
        visited[cur_h][cur_w] = true;
        dists[cur_h][cur_w] = steps++;
        int best_diff = INT_MAX, next_h, next_w;
        check3(cur_h, cur_w-1);
        check3(cur_h, cur_w+1);
        check3(cur_h-1, cur_w);
        check3(cur_h+1, cur_w);

        prec_h = cur_h, prec_w = cur_w,
        cur_h = next_h, cur_w = next_w;

    }
    return steps + dists[cur_h][cur_w];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> H >> W;
    for(int i=0; i<H; i++)
        for(int j=0; j<W; j++)
            cin >> A[i][j];

    cout << hike();
    return 0;
}
