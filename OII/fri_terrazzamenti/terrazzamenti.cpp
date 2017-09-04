#include <bits/stdc++.h>

using namespace std;
using ll = long long;
map<int, ll> computed; // piccolo speedup

int N, *elems;
#define int_abs(a) (a) > 0 ? (a) : -(a)
long long f(int h)
{
    if(h < 0)
        return numeric_limits<int>::max();
    ll res = 0;
    auto it = computed.find(h);
    if(it != computed.end()) return it->second;
    for(int i = 0; i < N; i++)
        res += int_abs(elems[i] - h - i);
    computed[h] = res;
    return res;
}

long long stima(int N, int* elems)
{
    ::N = N, ::elems = elems;
    int l = *min_element(elems, elems + N);
    int r = *max_element(elems, elems + N);

    while(l != r) // non proprio...
    {
        int C = (l + r) / 2;
        ll mid_res = f(C), prec_res = f(C-1), next_res = f(C+1);
        if(mid_res <= prec_res && mid_res <= next_res)
            return mid_res;
        else if(mid_res >= prec_res && mid_res <= next_res)
            r = C-1;
        else l = C+1;
    }
    return f(l);
}
