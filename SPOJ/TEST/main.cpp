#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    while(cin >> n, n != 42) cout << n << '\n';
    return 0;
}
