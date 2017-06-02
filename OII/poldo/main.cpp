#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

#define MAX_N 10000
int piatti[MAX_N];
int pile[MAX_N];
int N;

int lds() {
    pile[0] = piatti[0];
    int max_idx = 1;
    for(int i = 1; i < N; i++) {
        int idx = lower_bound(pile, pile + max_idx, piatti[i], greater<int>()) - pile;
        pile[idx] = piatti[i];
        if(idx >= max_idx) max_idx = idx + 1;
    }
    return max_idx;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", piatti + i);

    printf("%d\n", lds());
}
