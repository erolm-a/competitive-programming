#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_RANGE 1000000
#define MAX_N 40000
#define LSO(i) (i & -i)

struct orario {
    int da, a;
};

int ft[MAX_RANGE+1], N, max_fine;
orario orari[MAX_N];

void update(orario c) {
    c.da++;
    c.a += 2;
    while(c.da <= max_fine) ft[c.da] += 1, c.da += LSO(c.da);
    while(c.a <= max_fine) ft[c.a] -= 1, c.a += LSO(c.a);
}

int query(int i) {
    int res = 0; i++;
    while(i > 0) res += ft[i], i -= LSO(i);
    return res;
}

int pausa() {
    int somma = 0;
    for(int i = 0; i < N; i++)
        update(orari[i]);
    for(int i = 0; i < N; i++)
        somma += query(orari[i].da);

    return somma;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf(" %d %d", &orari[i].da, &orari[i].a);
        max_fine = max(max_fine, orari[i].a);
    }

    printf("%d\n", pausa());
}
