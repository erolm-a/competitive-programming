#include <stdio.h>

#define MAX_N 100000
int V[MAX_N];

int main()
{
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", V+i);

  int maximum = 0;
  for(int i = 0; i < n; i++)
    if(V[i] > maximum) {
      printf("%d\n", i+1);
      return 0;
    }
    else if(V[i] == maximum)
      maximum++;

    puts("-1");
}
