#include <cstdio>
#include <set>
#include <bitset>

using namespace std;

#define MAX_N 100000

void Vernicia(int indice, int colore)
{
    printf("%d %d\n", indice, colore);
}

void Diversifica(int N, int colore[])
{
    set<int> liberi;
    for(int i = 1; i <= N; i++)
        liberi.insert(i);
    set<int>::iterator it;

    for(int i = 0; i < N; i++)
        if((it = liberi.find(colore[i])) != liberi.end())
            liberi.erase(it);

    bitset<MAX_N+1> found;
    for(int i = 0; i < N; i++)
    {
        if(!found[colore[i]])
            found[colore[i]] = true;
        else {
            Vernicia(i, *liberi.begin());
            liberi.erase(liberi.begin());
        }
    }

}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N, cubetti[MAX_N];
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", cubetti + i);

    Diversifica(N, cubetti);
    return 0;

}
