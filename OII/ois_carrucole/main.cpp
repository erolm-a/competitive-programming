#include <cstdio>
#include <bitset>

using namespace std;

#define MAX_N 10000

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    bitset<MAX_N> carr_attive;
    int N, M, cont = 0;

    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) {
        int letto;
        scanf("%d", &letto);
        carr_attive[i] = (bool) letto;
    }

    for(int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        if(carr_attive[a] == false || carr_attive[b] == false)
            cont++;
    }

    printf("%d\n", M - cont);

    return 0;
}
