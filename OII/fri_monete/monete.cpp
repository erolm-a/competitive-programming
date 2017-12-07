#include <bits/stdc++.h>

#define MAX_N 100000

using namespace std;

bitset<MAX_N> isnotprime;
vector<int> primes;

void crivello(int N)
{
    isnotprime[0] = isnotprime[1] = true;
    for(int i = 2; i < N; i++)
        if(!isnotprime[i]) {
            primes.push_back(i);
            for(int j = 2*i; j < N; j+=i)
                isnotprime[j] = true;
        }
}

int monete(int N, int v[])
{
    crivello(N);

    unordered_map<int, int> counts;

    int max_count = 1;
    for(int p: primes)
    {
        counts.clear();
        for(int i = p-1; i < N; i+=p)
        {
            auto it = counts.find(v[i]);
            if(it == counts.end())
                counts[v[i]] = 1;
            else ++(it->second), max_count = max(it->second, max_count);
        }
    }
    return max_count;
}
