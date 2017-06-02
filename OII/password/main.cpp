#include <map>
#include <cstdio>
#include <cmath>

using namespace std;

#define MAX_N 10000000
#define MODULO 1000000007

map<long long, long long> nums;

long long K;
long long calcola()
{
    long long ris = 0;
    map<long long, long long>::iterator found;
    auto it = nums.begin();
    for(; it != nums.end() && K / it->first > it->first; it++) {
        if(K % it->first == 0 && (found = nums.find(K / it->first)) != nums.end())
            ris = (ris + (found->second * it->second) % MODULO) % MODULO;
    }
    if(it != nums.end() && K / it->first == it->first) {
        if(it->second % 2)
            ris = (ris + ((it->second - 1) / 2 * it->second) % MODULO) % MODULO;
        else
            ris = (ris + (it->second / 2 * (it->second - 1)) % MODULO) % MODULO;
    }
    return ris;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N;
    scanf("%d %lld", &N, &K);

    while(N--)
    {
        long long a;
        scanf("%lld", &a);
        auto it = nums.find(a);
        if(it != nums.end())
            it->second++;
        else
            nums[a] = 1;
    }
    printf("%lld", calcola());
}
