#include <cstdio>
#include <set>
#include <unordered_set>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 10000
#define MAX_M 100000

int vert[MAX_N];
int N;
struct arco_t {
    int vel, da, a;
};

bool operator<(const arco_t& a, const arco_t& b) {
    return a.vel > b.vel;
}

multiset<arco_t> archi;
int calcola() {
    int aggiornamento[MAX_N];
    arco_t aggiornati[MAX_N];
    int memo[MAX_N], ag_N;

    for(auto trovati = archi.equal_range(*archi.begin());; trovati = archi.equal_range(*trovati.second)) {
        ag_N = 0;
        for(auto it = trovati.first; it != trovati.second; it++) {
            aggiornati[ag_N++] = *it;
            aggiornamento[it->da] = memo[it->da];
            aggiornamento[it->a] = memo[it->a];
        }
        while(--ag_N >= 0)
            memo[aggiornati[ag_N].da] = max(memo[aggiornati[ag_N].da], aggiornamento[aggiornati[ag_N].a]+1);
        if(trovati.second == archi.end())
            break;
    }
    return *max_element(memo, memo + N);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int M;
    scanf("%d %d", &N, &M);
    while(M-- > 0) {
        int da, a, vel;
        scanf("%d %d %d", &da, &a, &vel);
        archi.insert(arco_t{vel, da, a});
    }
    printf("%d\n", calcola());
}
