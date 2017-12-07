#include <bits/stdc++.h>

using namespace std;

#define MAX_V 15000
int dim[MAX_V];

int N;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", dim + i);
    sort(dim, dim + N);
    long long ris = 0;
    for(int i = 0; i < N-2; i++) {
        int k = i+2;
        while(k < N && dim[k] <= dim[i] + dim[i+1]) k++;
        ris += (N - k);
        for(int j = i+2; j < N-1; j++) {
            //fprintf(stderr, "RIS: %lld\n", ris);
            while(k < N && dim[k] <= dim[i] + dim[j]) k++;

            //if(k > N) fprintf(stderr, "ALERT at %d %d %d\n", i, j, k);
            ris += (N - k);
            //fprintf(stderr, "%d %d %d %lld\n", i, j, k, ris);
        }
    }
    printf("%lld\n", ris);
}
