#include <algorithm>
#include <vector>
#include <cstdio>
#include <numeric>

using namespace std;

#define MAX_N 100000

int N;
int mandorle[MAX_N], cannella[MAX_N];
int sum[MAX_N+1];

int calcola() {
    if(N == 1) return 1;
    int minimi[MAX_N + 1], massimi[MAX_N + 1], min_size = 1, max_size = 1;
    minimi[0] = 0;
    massimi[0] = N;
    int commestibile[MAX_N];
    for(int i = 0; i < N; i++)
        commestibile[i] = cannella[i] - mandorle[i];
    partial_sum(commestibile, commestibile + N, sum + 1);

    for(int i = 1; i <= N; i++)
        // minimi è decrescente
        if(sum[minimi[min_size-1]] > sum[i])
            minimi[min_size++] = i;

   for(int i = N-1; i >= 0; i--)
       // massimi è crescente
       if(sum[massimi[max_size-1]] <= sum[i])
           massimi[max_size++] = i;

   // cerca la somma S(i, j) = sum[massimi[j]] - sum[massimi[i]]
   int sol = 0;
   max_size--;
   for(int i = 0; i < min_size && max_size > 0; i++) {
       while(max_size > 0 && sum[massimi[max_size-1]] >= sum[minimi[i]]) max_size--;
       sol = max(sol, massimi[max_size] - minimi[i]);
   }
   return sol;
}

int main()
{
    FILE *fr = fopen("input.txt", "r");
    FILE *fw = fopen("output.txt", "w");

    fscanf(fr, "%d", &N);
    for(int i = 0; i < N; i++)
        fscanf(fr, " %d", mandorle + i);
    for(int i = 0; i < N; i++)
        fscanf(fr, " %d", cannella + i);

    fprintf(fw, "%d\n", calcola());
}
