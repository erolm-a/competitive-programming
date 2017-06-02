#include <cstdio>
#include <algorithm>

using namespace std;

int A, B, X, Y;
int risolvi() {
    if(A < B)
        swap(A, B);
    if(X < Y)
        swap(X, Y);

    if(A >= X && B >= Y)
        return 0;
    if(A < X && B < Y && A != Y)
        return X*Y - A*B;
    if(A >= X && B < Y)
        return ((Y - B) / 2 + (Y - B) % 2) * X;


    return ((X - A) / 2 + (X - A) % 2) * Y;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d %d %d %d", &A, &B, &X, &Y);
    printf("%d\n", risolvi());

    return 0;
}
