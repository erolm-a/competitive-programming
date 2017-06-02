#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 100000
int main() {
    double stelle[MAX];
    int N, Q;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        long long a, b, c;
        scanf(" %lld %lld %lld", &a, &b, &c);
        stelle[i] = sqrt(a*a + b*b  + c*c);
    }
    sort(stelle, stelle + N);

    scanf(" %d", &Q);
    for(int i = 0; i < Q; i++)
    {
        int query;
        scanf(" %d", &query);
        int ris = upper_bound(stelle, stelle + N, (double) query) - stelle;
        printf("%d\n", ris);
    }

    return 0;
}
