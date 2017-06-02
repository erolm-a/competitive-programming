#include <cstdio>
#include <cassert>
#include <algorithm>

#define MAXN 1000000

using namespace std;
int spread(int N, int K, int H[]) {
    sort(H, H + N);

    int spread = MAXN;

    for(int i = K-1; i < N; i++) {
        if(H[i] - H[i - K + 1] < spread)
            spread = H[i] - H[i - K + 1];
    }

    return spread;
}


int H[MAXN];

int main() {
    FILE *fr, *fw;
    int N, K, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d %d", &N, &K));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &H[i]));

    fprintf(fw, "%d\n", spread(N, K, H));
    fclose(fr);
    fclose(fw);
    return 0;
}
