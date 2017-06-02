#include <fstream>
#include <algorithm>

using namespace std;

long long calcola(int X, int Y, int Z) {
    long long res = 0, Z2 = 0;
    if(X > 0) res += (X * 40);
    if(Z < 0) Z = 0;
    if(Y > 5000) Z += (Y - 5000);
    if(Z > 10000) Z2 = Z - 10000, Z = 10000;
    res += (Z  * 20 + Z2 * 60);
    return res;
}

int main()
{
    int X, Y, Z, W;
    ifstream i_f("input.txt");
    i_f >> X >> Y >> Z >> W;

    long long minimo = calcola(X - W, Y, Z);
    minimo = min(minimo, calcola(X, Y - W, Z));
    minimo = min(minimo, calcola(X, Y, Z - W));

    ofstream("output.txt") << minimo << '\n';
}
