#include <bits/stdc++.h>

static int K, N;

#define MAX_N 5000000
#define MAX_K 20

bool attack(int P);

#define MAX_T 330
int sums[MAX_T+1][MAX_K+1];
// somma i binomiali (t i) per i in [1, n] in O(n)
//int sum_of_binomials(int t, int n) {
//    int last = t, sum  = last;
//    for(int i = 1; i < n; i++) {
//        if(sum > MAX_N) return std::numeric_limits<int>::max();
//        sum+=(last = (last * (t-i)) / (i+1));
//    }
//    return sum;
//}

// quanti tentativi sono necessari per percorrere h piani avendo solo
// n uova, nel caso peggiore?
int _step(int n, int h)
{
    if(h < 2) return 1;
    // complessità O(klogN) [qualcuno mi dia un upper bound decente]
    int l = 1, r = 330;
    while(r - l > 1)
    {
        int m = (l + r)/2;
        int sum = sums[m][n];
        if(sum >= h) r = m;
        else l = m;
    }
    return r;
}

// qual è il miglior passo da percorrere al momento?
int step(int n, int h)
{
    if(h < 2) return 1;
    if(n == 2) // speedup quasi O(1)
        return (sqrt(1 + 8*h) - 1)/2;

    int c = _step(n, h) - 1;

    int l = 0, r = h;
    int a = -1, b = -1;
    int x;
    while(std::max(a, b) != c)
    {
        x = (l + r) / 2;
        a = _step(n-1, x-1), b = _step(n, h - x);
        if(a <= c && b >= c) l = x;
        else r = x;
    }
    return x;
}

int calcola(int begin, int end, int K) // tail call recursion + GCC, aiutatemi voi!
{
    if(K >= log(end - begin) / log(2) && K > 1)
    {
        // cerchiamo il primo elemento i tale che attack(i) dia falso
        int l = begin-1, r = end;
        while(r - l > 1)
        {
            int m = (l+r)/2;
            if(attack(m))
                l = m;
            else r = m;
        }
        return l;
    }
    if(K == 1)
    {
        while(begin < end) {
            if(!attack(begin))
                return begin-1;
            begin++;
        }
        return end-1;
    }
    int m = step(K, end - begin);
    bool ok = true;
    int i, hope = begin;
    for(i = begin + m-1; i < end; hope = i, i += (m = step(K, end - hope - 1)))
        if(!attack(i))
        {
            ok = false;
            i -= m;
            break;
        }
    if(ok && i - m < end - 1) {
        if(attack(end-1))
            return end - 1;
        else if(end - 1 - hope == 1)
            return hope;
        return calcola(hope+1, end-1, K-1);
    }
    else if(!ok) return calcola(hope + (hope!=begin), i + m, K-1);
    return end-1;
}

void init(int N, int K)
{
    ::K = K, ::N = N;
    for(int t = 1; t <= MAX_T; t++) {
        // calcoliamo con DP... ci conviene
        int last = t;
        sums[t][1] = t;
        for(int u = 2; u < MAX_K; u++) {
            if(sums[t][u-1] > MAX_N) sums[t][u] = std::numeric_limits<int>::max();
            else
                sums[t][u] = sums[t][u-1] + (last = (last * (t-u+1)) / (u));
        }
    }
}

int new_pokemon()
{
    return calcola(0, N, K) + 1;
}
