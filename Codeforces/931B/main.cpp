#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int A, B, n;
    cin >> n >> A >> B;
    n = log2(n);
    --A; --B;
    int step;
    for(step = 1; abs(A-B) > 1; step++)
        A>>=1, B>>=1;
    if(n == step)
        cout << "Final!" << endl;
    else cout << step << endl;
}
