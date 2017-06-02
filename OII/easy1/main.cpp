#include <cstdio>
#include <limits>

using namespace std;

int main()
{
    int N, min = -1000;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &N);
    while(N-- > 0) {
        int n;
        scanf("%d", &n);
        if(n > min) min = n;
    }
    printf("%d\n", min);
}
