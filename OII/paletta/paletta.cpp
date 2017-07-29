#include <bits/stdc++.h>
#define MAX_N 15000000
int pari[MAX_N/2], dispari[MAX_N/2];
int N;

// Con merge sort
//long long int mergesort(int *begin, int* end)
//{
//    if(end - begin == 1)
//        return 0;
//    auto n = (end - begin), mid = n / 2;
//    long long res = mergesort(begin, begin + mid) + mergesort(begin + mid, end);

//    int j = mid;
//    for(int i = 0; i < mid; i++)
//        while(j < n && begin[j] < begin[i])
//            res += (mid - i), j++;
//    std::inplace_merge(begin, begin + mid, end);
//    return res;
//}

//long long int paletta_sort(int N, int* V)
//{
//    // pari ai posti pari e viceversa
//    for(int i = 0; i < N; i++) {
//        if((i % 2 && V[i] % 2 != V[1] % 2 ) ||
//            (i % 2 == 0 && V[i] % 2 != V[0] % 2))
//            return -1;
//        if(i % 2) dispari[i/2] = V[i];
//        else pari[i/2] = V[i];
//    }

//    return mergesort(pari, pari + N/2 + N%2) +
//            mergesort(dispari, dispari + N/2);
//}

struct Fenwick
{
    long long tree[MAX_N/2 + 2];
    void update(int i) {i++; do tree[i]++; while((i += (i & -i)) <= N/2 +1);}
    long long query(int i) {long long res = 0; i++; do res += tree[i]; while(i -= (i & -i)); return res;}
} f_pari, f_dispari;

long long calcola(int *V, int size, Fenwick& f)
{
    int m = V[size-1]/2;
    long long ris = 0;
    for(int i = size-1; i >= 0; i--)
    {
        int dim = V[i]/2;
        if(m > dim) m = dim;
        f.update(dim);
        ris += f.query(dim) - f.query(m);
    }
    return ris;
}

long long int paletta_sort(int N, int* V)
{
    ::N = N;
    // pari ai posti pari e viceversa
    for(int i = 0; i < N; i++) {
        if((i % 2 && V[i] % 2 != V[1] % 2 ) ||
            (i % 2 == 0 && V[i] % 2 != V[0] % 2))
            return -1;
        if(i % 2) dispari[i/2] = V[i];
        else pari[i/2] = V[i];
    }
    return calcola(pari, N/2 + N % 2, f_pari) +  calcola(dispari, N/2, f_dispari);
}
