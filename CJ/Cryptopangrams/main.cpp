#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll gcd(ll a, ll b) {
    if(a < b)
        return gcd(b, a);
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int tcs;
    cin >> tcs;
    for(int tc = 1; tc <= tcs; tc++) {
        cout << "Case #" << tc << ": ";

        set<ll> primes;
        map<ll, char> lookup;

        vector<ll> numbers;
        vector<ll> sol_num;
        ll N, L;
        cin >> N >> L;
        numbers.resize(L);
        sol_num.resize(L+1);
        for(int i = 0; i < L; i++)
            cin >> numbers[i];

        for(int i = 0; i < L - 1; i++) {
            if(numbers[i] / ((long long)sqrtf(numbers[i])) == numbers[i])
                sol_num[i+1] = sqrtl(numbers[i]);
            else
                sol_num[i+1] = gcd(numbers[i], numbers[i+1]);
        }
        sol_num[0] = numbers[0] / sol_num[1];
        sol_num[L] = numbers[L-1] / sol_num[L-1];

        for(ll i : sol_num)
            primes.insert(i);

        char ch = 'A';
        for(ll p: primes)
            lookup[p] = ch++;

        for(ll p: sol_num)
            cout << lookup[p];
        cout << endl;
    }
}
