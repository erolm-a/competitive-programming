#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

#define MAX_N 10000000

pii voti[MAX_N];

constexpr int base = 8;

int counter[1 << base];
pii c[MAX_N];
int N;


// base 16
int getdigit(int a, int b) { return (a & (((1<<base) - 1) << base*b) ) >> base*b;}
void countingsort(int digit)
{
    memset(counter, 0, sizeof counter);
    for(int i = 0; i < N; i++)
        counter[getdigit(voti[i].first, digit)]++;

    for(int i = 0, sum = 0; i < (1 << base); i++) {
        int t = counter[i]; counter[i] = sum, sum += t;
    }

    for(int i = 0; i < N; i++)
        c[counter[getdigit(voti[i].first, digit)]++] = voti[i];

    copy(c, c + N, voti);
}

void radixsort()
{
   for(int i = 0; i < 4; i++)
        countingsort(i);
}

long long solve(int N, int* M, int* P)
{
    ::N = N; int i;
    for(i = 0; i < N; i++)
        voti[i] = {M[i] - P[i] + MAX_N, i};

    radixsort();

    long long sol = 0;
    for(i = N-1; i >= N/2; i--)
        sol += M[voti[i].second];
    for(; i >= 0; i--)
        sol += P[voti[i].second];

    return sol;
}
