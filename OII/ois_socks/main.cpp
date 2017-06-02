#include <cstdio>
#include <map>

using namespace std;

int main()
{
    map<int, int> socks;
    int last_pos = 0, N, C;
    long long res = 0;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // trick: se ci sono 100000 calze al massimo, non ci possono essere più colori.
    // al massimo, è possibile avere tonalità a casaccio.
    scanf("%d %d", &N, &C);
    for(int i = 0; i < N; i++) {
        int found = 0;
        scanf("%d", &found);
        auto it = socks.find(found);
        if(it == socks.end())
            socks[found] = last_pos, res += last_pos, last_pos++;
        else
            res += it->second;
    }
    printf("%lld\n", res);
    return 0;
}
