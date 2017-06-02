#include <algorithm>
using namespace std;

int* set, n, k;
#define MAX_K 100000
bool visited[MAX_K];

inline int isfound(int e) {
    int l = 0, h = n;
    while(l != h)
    {
        int m = (l + h) / 2;
        if(set[m] == e) return m;
        if(set[m] > e) h = m;
        else l = m+1;
    }
    return n;
}

int Trova(int n, int k, int insieme[])
{
    ::set = insieme;
    ::n = n, ::k = k;
    if(k == 1) return 0;
    sort(insieme, insieme + n);

    int ris = 0;
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            for(int j = set[i], pos = isfound(j), m = 1;
                pos < n;
                visited[pos] = true, j*=k, pos = isfound(j), ris += m, m^=1)
                ;
        }
    }
    return ris;
}
