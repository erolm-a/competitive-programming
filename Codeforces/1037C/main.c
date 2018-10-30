#include <stdio.h>

#define MAX (int)(10e6)
char V1[MAX+1], V2[MAX+1];
int N;
int cost;
int main()
{
    scanf("%d", &N);
    scanf("%s %s", V1, V2);

    for(int i = 0; i < N; i++) 
      if(V1[i] != V2[i]) {
        // simple swap -> 01... and 10...
        if(i < N - 1 && V1[i+1] != V1[i] && V1[i+1] != V2[i+1])
            cost++, i++;
        // general: two digits to swap are too distant
        else cost++;
      }

    printf("%d\n", cost);
}
