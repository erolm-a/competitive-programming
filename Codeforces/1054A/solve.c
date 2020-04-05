#include <stdio.h>
#include <stdlib.h>

int main()
{
  int x, y, z, t1, t2, t3;
  scanf("%d%d%d%d%d%d", &x, &y, &z, &t1, &t2, &t3);

  if(abs(y-x)*t1 >= (abs(z-x)+abs(y-x))*t2 + (2+(z!=x))*t3)
    printf("YES\n");
  else printf("NO\n");
}
