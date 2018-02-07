#include <iostream>
#include <cmath>

using namespace std;

int digitsum(int x) {
    int sum=0;
    while(x)
        sum+=(x%10), x/=10;
    return sum;
}
int main()
{
    long long N;
#ifdef EVAL
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%lld", &N);

    for(int s = 1; s <= 81; s++) {
        long long x = (sqrt(s*s + 4*N) - s) / 2ll;
        if(digitsum(x) == s && x*x + x*s - N == 0) {printf("%lld\n", x); return 0;}
    }
    puts("-1");
}
