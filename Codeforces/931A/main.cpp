#include <iostream>

using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;
    int dist = abs(A - B);
    cout << (dist / 2) * ((dist/2) + 1) / 2 + (dist/2 + dist%2)*(dist/2 + dist%2 + 1)/2 << '\n';
}
