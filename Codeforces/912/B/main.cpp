#include <iostream>

using namespace std;

int main()
{
    uint64_t n, k;
    cin >> n >> k;
    uint64_t p2 = 1;
    while(p2<<1 <= n) p2 <<=1;
    cout << (k > 1 ? (p2 | (p2-1)) : n);
}
