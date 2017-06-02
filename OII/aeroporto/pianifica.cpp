#include <algorithm>
#include <cassert>
int N, *Part, *Arr, *scelti;

#define MAX_N 100000

bool possibile(int K) {
    int candidato[MAX_N];

    candidato[0] = Part[0];
    for(int i = 1; i < N; i++) {
        if(candidato[i-1] + K > Arr[i])
            return false;
        if(candidato[i-1] + K < Part[i])
            candidato[i] = Part[i];
        else candidato[i] = candidato[i-1] + K;
    }
    std::copy(candidato, candidato + N, scelti);
    return true;
}

void pianifica(int R, int A[], int B[], int T[])
{
    N = R, Part = A, Arr = B, scelti = T;
    int l = 1, r = (B[N-1] - A[0]) / (N - 1);
    if(!possibile(2))
        possibile(1);
    else
        while(r > l) {
            int m = (l + r + 1) / 2;
            if(possibile(m))
                l = m;
            else
                r = m - 1;
        }
}
