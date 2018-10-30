#include <cstdio>
#include <algorithm>

using namespace std;

int attaccanti[3], difensori[3];

int main()
{
    int A, D, d;
    scanf("%d %d %d", &d, &A, &D);
    for(int i = 0; i < A; i++) {
        int ya, yb;
        scanf("%*s %d %*s %d", &ya, &yb);
        attaccanti[i] = 10*ya + (yb - ya)*d;
    }
    for(int i = 0; i < D; i++) {
        int ya, yb;
        scanf("%*s %d %*s %d", &ya, &yb);
        difensori[i] = 10*ya + (yb - ya)*d;
    }


    auto a = *min_element(attaccanti, attaccanti + A);
    auto b = *min_element(difensori, difensori + D);
    printf("%c\n", "RF"[b > a]);
}
