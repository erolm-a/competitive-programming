#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_N 10000000
#define MODULO 1000000007
long long A[MAX_N], N, K;

#define EVAL
int main()
{
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%lld %lld", &N, &K);
    for(int i = 0; i < N; i++)
        scanf("%lld", A+i);

    sort(A, A + N);
    long long ris = 0;
    for(int i = 0, j = N-1; i < N && j >= i && A[i]*A[i]<=K; i++) {
        if(K % A[i]) continue;
        while(A[i]*A[j] > K) j--;
        long long r = 0ll, re = 0ll;
        if(A[i] * A[j] == K)
        {
            if(A[i] != A[j]) {
                while(A[i]*A[j] == K) r++, i++;
                i--;
                while(A[i]*A[j] == K) re+=r, j--;
            }
            else {
                while(A[i]*A[i] == K) r++, i++;
                re = r*(r-1)/2;
            }
        }
        ris+=re;
    }
    printf("%lld\n", ris);
}
