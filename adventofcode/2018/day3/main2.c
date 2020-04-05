#include <stdio.h>
#include <stdbool.h>


#define SIZE 2000
struct rect {
  int x, y, width, height;
} rects[SIZE];
bool checked[SIZE];

bool intersect(struct rect* rect1, struct rect* rect2) {
    if(rect1->x >= rect2->x+rect2->width || rect2->x >= rect1->x + rect1->width)
        return false;
    if(rect1->y + rect1->height <= rect2->y || rect2->y + rect2->height <= rect1->y)
        return false;

    return true;
}
int main()
{
    FILE* f = fopen("input", "r");
    int left, top, width, height, n;
    while(fscanf(f, " #%d @ %d,%d: %dx%d", &n, &left, &top, &width, &height) != EOF)
        rects[n-1] = (struct rect){left, top, width, height};

    for(int i = 0; i < n; i++) {
      bool ok = true;
      for(int j = 0; j < n; j++)
        if(i != j && intersect(rects + i, rects + j)) {
          ok = false;
          break;
        }
      if(ok) {
        printf("%d\n", i+1);
        return 0;
      }
    }
}
