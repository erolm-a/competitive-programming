#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1000
int x[MAX_N], r;
double y[MAX_N];
int N;

int main()
{
    scanf("%d %d", &N, &r);
    for(int i = 0; i < N; i++)
        scanf("%d", x + i);

    y[0] = r;
    for(int i = 1; i < N; i++) {
        double t_y = r;
        for(int j = 0; j < i; j++) {
            if(abs(x[i] - x[j]) > 2*r) continue;
            t_y = max(t_y, y[j] + sqrt(4*r*r-(x[i]-x[j])*(x[i]-x[j])));
        }
        y[i] = t_y;
    }

    for(int i = 0; i < N; i++)
        printf("%.12f ", y[i]);
}
