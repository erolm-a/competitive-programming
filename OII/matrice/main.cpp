#include <bits/stdc++.h>

using namespace std;

#define MAX_N 500
#define PRIME_LIMIT 100003

int toprime[MAX_N][MAX_N];

vector<int> primes;
bitset<PRIME_LIMIT+1> marked;

void genera()
{
    primes.push_back(2);
    marked[0] = marked[1] = true;
    for(int i = 2; i <= PRIME_LIMIT; i++)
        if(!marked[i]) {primes.push_back(i); for(int j = 2*i; j <= PRIME_LIMIT; j+=i) marked[j] = true;}
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    genera();
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            int x;
            scanf(" %d", &x);
            toprime[i][j] = marked[x] ? *upper_bound(primes.begin(), primes.end(), x) - x : 0;
        }

    int sol = INT_MAX;
    for(int i = 0; i < n; i++)
        sol = min(sol, accumulate(toprime[i], toprime[i] + m, 0));

    for(int i = 0; i < m; i++) {
        int sum = 0;
        for(int j = 0; j < n; j++)
            sum += toprime[j][i];
        sol = min(sol, sum);
    }

    printf("%d\n", sol);
}
