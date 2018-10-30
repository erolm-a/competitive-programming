#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define MAX_N 1000000

int numbers[MAX_N];

unordered_map<ll, int> memo;

int N, K;

ll potenze[10];
int main()
{
    cin >> N >> K;
    for(int i = 0; i < N; i++)
        cin >> numbers[i];

    potenze[0] = 1;
    for(int i = 1; i <= K; i++)
        potenze[i] = 10ll*potenze[i-1];

    long long num = 0;
    for(int i = N - K; i < N; i++)
        num = num*10 + numbers[i];

    memo[num]++;

    for(int i = N-K-1; i >=0; i--) {
        num = num/10 + numbers[i]*potenze[K-1];
        memo[num]++;
    }

    int ris_m = 0; long long ris = 0;
    for(auto v: memo)
        if(v.second > ris_m)
            ris_m = v.second, ris = v.first;

    vector<int> digits;
    for(int i = 0; i < K; i++) {
        digits.push_back(ris % 10);
        ris /= 10;
    }
    for(int i = 0; i < K; i++) {
        cout << digits.back() << ' ';
        digits.pop_back();
    }

}
