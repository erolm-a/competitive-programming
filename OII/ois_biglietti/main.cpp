#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N, M, A, B, ris = 0;
    scanf("%d %d %d %d", &N, &M, &A, &B);

    while(N>0)
        if(B > min(N, M)*A)
            ris += A, N--;
        else
            ris += B, N-=M;
    printf("%d\n", ris);
    return 0;
}
