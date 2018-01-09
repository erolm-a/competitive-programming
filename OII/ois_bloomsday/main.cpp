#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int K, E; long long h = 0, prec_h = 0, s = 0, X;
    cin >> K >> E >> X;
    int i;

    for(i = 1;;i++) {
        h = ceil(pow(pow(10, i-1)/K, 1./E));
        s += (h - prec_h)*(i-1);
        if(s >= X) {
            s-=(h - prec_h)*(--i);
            break;
        }
        prec_h = h;
    }
    X-=(s+1);
    cout << prec_h + X/i << '\n';
}
