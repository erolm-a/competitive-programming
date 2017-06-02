#include <cmath>
#include <cstdio>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    double a, b;
    scanf("%lf %lf", &a, &b);
    printf("%ld\n", (unsigned long) (floor(sqrt(b)) -  ceil(sqrt(a))) + 1);
}
