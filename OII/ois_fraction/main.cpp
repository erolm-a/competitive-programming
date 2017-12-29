#include <vector>
#include <bitset>
#include <iostream>

using namespace std;

#define MAX_N 1000001
bitset<MAX_N> vis;

vector<int> primes, divider;

int modularexponentation10(int p, int k)
{
    int ris = 1, n = 10;
    for(ris = 1; k; k>>=1) {
        if(k % 2) ris = (ris * n) % p;
        n = (n * n) % p;
    }

    return ris;
}

bool root10(int p) {
    if(p < 7) return false;
    divider.clear();
    for(int i = 0; i < primes.size() && primes[i]*primes[i] <= p-1; i++) {
        if((p-1) % primes[i] == 0) {
            divider.push_back(primes[i]);
            if(!vis[(p-1) / primes[i]])
                divider.push_back((p-1) / primes[i]);
        }
    }
    for(int q: divider)
        if(modularexponentation10(p, (p-1)/q) == 1)
            return false;
    return true;
}

int solve(int N)
{
    int sol;
    for(int i = 2; i < N; i++) {
        if(!vis[i]) {

            primes.push_back(i);
            sol = (root10(i) ? i : sol);
            for(int j = i*2; j < N; j+=i) vis[j] = true;
        }
    }
    return sol;
}

int main()
{
    int N;
    cin >> N;

    if(N <= 3) cout << N-1;
    else if(N <= 6) cout << 3;
    else if(N <= 7) cout << 6;
    else cout << solve(N);

    cout << '\n';
}
