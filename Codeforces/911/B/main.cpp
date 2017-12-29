#include <iostream>

using namespace std;
int main(int argc, char *argv[])
{
    int a, b, n;
    ios_base::sync_with_stdio(false);
    cin >> n >>a >> b;

    int x;
    for(x=1; x <= min(a,b);x++)
        if(a/x+b/x < n) break;

    cout << x-1 << '\n';
}
