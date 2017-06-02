#include <stdio.h>

using namespace std;

int main()
{
    int i = 1, N;
    FILE* fr = fopen("input.txt", "r");
    FILE* fw = fopen("output.txt", "w");
    fscanf(fr, "%d", &N);

    for(;N>1;i++)
        N = N % 2 ? 3*N + 1 :N/2;
    fprintf(fw, "%d\n", i);
}
